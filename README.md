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
## Display Device
### Diagram
*(Include a detailed sketch of the display device here after creating it and uploading to the `diagrams/` folder.)*

### Description
- **Stepper Motor Gauge**: Displays posture quality on a scale.
- **LED Indicator**: Lights up red for poor posture.
- **Power**: Powered by AAA batteries.
- **Communication**: Receives data from the wearable device via BLE.
## System Architecture
### Communication Diagram
*(Include a diagram showing BLE communication between devices here after creating it.)*

### Functionality Diagram
*(Include a flowchart showing data processing and system functionality here after creating it.)*
## Datasheets
Datasheets for all components are included in the `datasheets/` folder:
- IMU Sensor: **MPU6050**
- BLE Module: **nRF52832**
- Stepper Motor: Example: **28BYJ-48**
- LED: High-brightness red LED (e.g., **5mm LED**)
