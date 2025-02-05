#include <WiFi.h>
#include <FirebaseESP32.h>
#include "esp_sleep.h"

// Pin configuration
#define TRIG_PIN 9
#define ECHO_PIN 10

// WiFi credentials
const char* WIFI_SSID = "victhevictor";
const char* WIFI_PASS = "victoriaisgreat";

// Firebase configuration
#define FIREBASE_URL "https://battery-managemnt-lab-default-rtdb.firebaseio.com"
#define FIREBASE_API_KEY "AIzaSyAv28hmtkVrxGsEnTdg2ado0NkDtpD4wWg"

// Firebase objects
FirebaseData firebaseData;
FirebaseAuth firebaseAuth;
FirebaseConfig firebaseConfig;

// Ultrasonic sensor variables
long pulseDuration;
int measuredDistance;

// Connect to WiFi
void connectToWiFi() {
    Serial.print("Connecting to WiFi");
    WiFi.begin(WIFI_SSID, WIFI_PASS);

    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    Serial.println("\nWiFi Connected!");
}

// Initialize Firebase
void initializeFirebase() {
    firebaseConfig.api_key = FIREBASE_API_KEY;
    firebaseConfig.database_url = FIREBASE_URL;

    if (Firebase.signUp(&firebaseConfig, &firebaseAuth, "", "")) {
        Serial.println("Firebase authentication successful.");
    } else {
        Serial.println("Firebase authentication failed.");
        return;
    }
    Firebase.begin(&firebaseConfig, &firebaseAuth);
    Firebase.reconnectWiFi(true);
}

// Measure distance using ultrasonic sensor
void getUltrasonicDistance() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    pulseDuration = pulseIn(ECHO_PIN, HIGH);
    measuredDistance = pulseDuration * 0.034 / 2;

    Serial.print("Measured Distance: ");
    Serial.print(measuredDistance);
    Serial.println(" cm");
}

// Send distance data to Firebase
void sendToFirebase(int distance) {
    if (Firebase.setInt(firebaseData, "/sensor/distance", distance)) {
        Serial.println("Data successfully sent to Firebase.");
    } else {
        Serial.println("Failed to send data to Firebase.");
        Serial.println(firebaseData.errorReason());
    }
}

// Enter deep sleep mode
void enterDeepSleep() {
    Serial.println("\n[System Sleep Mode]");
    Serial.println("Entering deep sleep for 2 seconds...");
    esp_sleep_enable_timer_wakeup(60 * 1000000); // Sleep for 2 seconds
    esp_deep_sleep_start();
}

void setup() {
    Serial.begin(115200);
    
    connectToWiFi();       // Connect to WiFi
    initializeFirebase();  // Initialize Firebase
}

void loop() {
    getUltrasonicDistance();  // Measure distance
    sendToFirebase(measuredDistance); // Send data to Firebase

    delay(1000); // Maintain transmission interval

    if (measuredDistance < 20) {
        enterDeepSleep();  // Trigger deep sleep if distance is below threshold
    }
}