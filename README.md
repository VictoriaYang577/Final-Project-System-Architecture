# Final-Project-System-Architecture
# Posture Monitoring Assistant

## Overview
A wearable device that uses an IMU (gyroscope and accelerometer) to monitor body posture. The device provides real-time feedback through a stepper-motor gauge and an LED indicator. It employs BLE communication for low-latency feedback and a rechargeable battery for portability.
## Sensor Device
### Diagram
*(Include a detailed sketch of the wearable device here after creating it and uploading to the `diagrams/` folder.)*

### Description
- **IMU Sensor**: Tracks gyroscopic and accelerometer data (e.g., MPU6050).
- **BLE Module**: Facilitates communication with the display (e.g., nRF52832).
- **Power**: Powered by a rechargeable battery.
- **Processing**: Onboard ML model detects slouching patterns.
