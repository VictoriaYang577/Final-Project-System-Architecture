# Final-Project-System-Architecture
# Posture Monitoring Assistant

## Overview
A wearable device that uses an IMU (gyroscope and accelerometer) to monitor body posture. The device provides real-time feedback through a stepper-motor gauge and an LED indicator. It employs BLE communication for low-latency feedback and a rechargeable battery for portability.
## Sensor Device
### Diagram
![image](https://github.com/user-attachments/assets/b00c221d-7946-4321-b4dc-554029936d30)


### Description
- **IMU Sensor**: Tracks gyroscopic and accelerometer data (e.g., MPU6050).
- **BLE Module**: Facilitates communication with the display (e.g., nRF52832).
- **Power**: Powered by a rechargeable battery.
- **Processing**: Onboard ML model detects slouching patterns.
## Display Device
### Diagram

![Screenshot 2025-01-21 at 23 57 04](https://github.com/user-attachments/assets/337a364f-2822-42d7-8933-00ecd073dd45)

### Description
- **Stepper Motor Gauge**: Displays posture quality on a scale.
- **LED Indicator**: Lights up red for poor posture.
- **Power**: Powered by AAA batteries.
- **Communication**: Receives data from the wearable device via BLE.
## System Architecture
### Communication Diagram
![image](https://github.com/user-attachments/assets/a871c7f6-ef6a-4f0d-8acf-3ec77a0200ab)


### Functionality Diagram
![image](https://github.com/user-attachments/assets/c7d0edbe-4e6b-4c31-986d-1663e46089f4)
![image](https://github.com/user-attachments/assets/f33ae50f-99e1-45a7-906c-3a6d0c4853f2)
![image](https://github.com/user-attachments/assets/119a05b4-7333-42c4-b19a-a0c6977f642b)
![image](https://github.com/user-attachments/assets/a871c7f6-ef6a-4f0d-8acf-3ec77a0200ab)
## Datasheets
Datasheets for all components are included in the `datasheets/` folder:
- IMU Sensor: **MPU6050**
- BLE Module: **nRF52832**
- Stepper Motor: Example: **28BYJ-48**
- LED: High-brightness red LED (e.g., **5mm LED**)
