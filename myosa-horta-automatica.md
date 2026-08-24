---
publishDate: 2026-08-24 T00:00:00Z
title: Automated Irrigation System for a Community Garden using Myosa Systems
excerpt: An automated irrigation system for a community garden at Escola do Bairro in Sarandi, Paraná, using the Myosa platform to combine environmental sensing, automation, and STEM education.
image: cover.jpeg
tags:
  - Automated Irrigation System
  - Myosa IoT Mini Kit
  - Extension and Community
---

<p align="center">
  <img src="cover.jpeg" width="800"><br/>
  <i>Automated irrigation system developed for the community garden at Escola do Bairro.</i>
</p>

> Automating irrigation while bringing technology, sustainability, and STEM education to the community garden.

---

## Acknowledgements

The Automated Irrigation System for a Community Garden using Myosa Systems was developed by João Marcos, Laura Gasparotti, Maria Eduarda Bezerra, and Bruno Schimdt for Escola do Bairro and the Myosa IEEE Event. We acknowledge Myosa and IEEE for making this project possible and for supporting us throughout its development.

---

## Overview

The proposed project aims to implement an automated community garden at Escola do Bairro, located in Sarandi, Paraná, Brazil, using the Myosa platform as the core technological solution. This initiative seeks to support the daily activities of the school's teachers and volunteers while creating meaningful educational opportunities for children from low-income communities. Through hands-on experiences involving robotics, electronics, environmental sensing, and automation, the project intends to democratize access to technological knowledge and inspire young students to engage with STEM fields.

This initiative builds upon previous automated garden projects developed by the IEEE Student Branch at the State University of Maringá (UEM) at the same school. Although those earlier implementations generated positive outcomes, they also faced several hardware and software limitations that affected their long-term operation and scalability. By adopting the Myosa platform, the proposed project seeks to overcome many of these challenges through a more reliable, accessible, and easily maintainable solution, thereby significantly increasing its educational and social impact within the local community.

**Key features:**
* Soil moisture identification for irrigation control
* Automatic irrigation based on soil moisture and light conditions
* Day and night cycle verification
* Barometric pressure monitoring for educational activities
* Temperature monitoring to protect the plants

---

## Demo / Examples

### Images

The following images show the development, assembly, and operation of the automated irrigation system.

<!-- IMAGE 1: COVER / COMPLETE SYSTEM -->
<p align="center">
  <img src="cover.jpeg" width="800"><br/>
  <i>Complete automated irrigation system developed using the Myosa platform.</i>
</p>

<!-- IMAGE 2: HARDWARE -->
<p align="center">
  <img src="System-acionamento.jpeg" width="800"><br/>
  <i>Solenoid Valve Control Systemt.</i>
</p>

<!-- IMAGE 3: SENSOR SYSTEM -->
<p align="center">
  <img src="Sensors.jpeg" width="800"><br/>
  <i>Sensors used for environmental monitoring and irrigation control.</i>
</p>

<!-- IMAGE 4: Block Diagram -->
<p align="center">
  <img src="Block-Diagram2.png" width="800"><br/>
  <i>System Block Diagram.</i>
</p>

<!-- Add additional images here if necessary -->

### Videos

The project demonstration video is provided as a local MP4 file, following the MYOSA submission requirements.

https://github.com/user-attachments/assets/5b8ea8f3-b0c4-4a1d-9f9d-8bfeb1d502ad?

---

## Features (Detailed)

### 1. Soil Moisture Identification

Soil moisture will be monitored using the HW103 module and its conductive fork-shaped probe, which is inserted directly into the soil. The sensor provides the information required to determine whether the soil is sufficiently moist or dry, serving as one of the main conditions for activating the irrigation system.

The soil moisture threshold used by the system will be defined according to the sensor calibration and experimental tests performed in the garden.

### 2. Automatic Garden Irrigation

The irrigation system is the main functionality of the project. Water is distributed through a hose connected to specific points throughout the garden, allowing the plants to be irrigated across the cultivated area.

Irrigation will only be activated when the soil moisture sensor indicates dry soil and the APDS9960 sensor indicates low ambient light. This combination of conditions ensures that irrigation takes place during the night and only when the plants require water.

The solenoid valve is controlled electronically through an IRFZ44N MOSFET and a relay, allowing the irrigation system to be activated automatically according to the environmental conditions detected by the sensors.

### 3. Day and Night Cycle Verification

The day and night cycle will be identified using the APDS9960 sensor. The sensor provides ambient light information that can be used both to monitor the environmental conditions of the garden and to determine whether the conditions are suitable for irrigation.

The measured light level can also be displayed on the OLED screen, providing an opportunity to introduce students to concepts related to ambient light and, if incorporated into the educational activities, the lux unit.

The ambient light threshold used to identify nighttime conditions will be defined according to the sensor calibration and experimental tests.

### 4. Barometric Pressure Education

Barometric pressure information will be collected using the BMP180 sensor and displayed on the OLED screen. This functionality provides an opportunity to introduce students to the concept of atmospheric pressure and demonstrate how environmental data can be collected and displayed using electronic sensors.

The display of environmental measurements is intended to support educational activities and encourage students to interact with the technological system installed in the community garden.

### 5. Temperature Monitoring

The system will also monitor temperature as an additional environmental parameter. Temperature information can be used to prevent irrigation under excessively hot conditions, reducing the risk of applying water during unfavorable conditions for the plants and helping protect the garden.

The temperature information will also be available through the OLED display, allowing students to observe changes in environmental conditions.

---

## Usage Instructions

The system is designed to operate automatically after the electronic hardware and sensors have been installed and configured.

### Hardware Setup

1. Install the MYOSA IoT Kit and ESP32 in the control system.
2. Connect the HW103 soil moisture sensor and insert its conductive probe into the soil.
3. Connect the APDS9960 sensor to measure ambient light.
4. Connect the BMP180 sensor for barometric pressure and temperature measurements.
5. Connect the OLED display for visualization of the environmental data.
6. Connect the solenoid valve to the irrigation hose system.
7. Use the IRFZ44N MOSFET and relay to control the solenoid valve.
8. Verify all electrical connections before powering the system.

### System Operation

After the system is powered, the sensors continuously collect environmental information.

The irrigation system checks the soil moisture and ambient light conditions. The solenoid valve is activated only when the soil is considered dry and the ambient light level indicates nighttime conditions.

The OLED display provides environmental information collected by the sensors, including temperature, barometric pressure, and ambient light measurements.

### Sensor Thresholds

The thresholds used to determine soil dryness and nighttime conditions must be defined according to the calibration and experimental tests of the installed sensors.

* **Soil moisture threshold:** To be defined after calibration.
* **Ambient light threshold:** To be defined after calibration.

---

## Tech Stack

* **Hardware:** MYOSA IoT Kit, ESP32, OLED Display, BMP180 Sensor, APDS9960 Sensor, HW103 soil moisture module, solenoid valve, IRFZ44N MOSFET, relay
* **Firmware:** Arduino C++
* **Communication and Data Acquisition:** I2C sensor communication and serial data stream
* **Sensors:** LM393 soil moisture sensor, BMP180 barometric pressure sensor, APDS9960 ambient light sensor
* **Actuation:** Solenoid valve controlled by an IRFZ44N MOSFET and relay

---

## Requirements / Installation

The project requires the MYOSA IoT Kit, an ESP32 development board, the sensors used for environmental monitoring, the OLED display, and the irrigation control components.

### Hardware Requirements

* MYOSA IoT Kit
* ESP32
* OLED Display
* HW103 soil moisture module with conductive probe
* BMP180 sensor
* APDS9960 sensor
* Solenoid valve
* IRFZ44N MOSFET
* Relay
* Irrigation hose and connections

### Software Requirements

* Arduino IDE
* Arduino C++ development environment
* MYOSA libraries
* Required sensor libraries
* ESP32 board support package for Arduino IDE

The specific libraries and installation procedure should be added according to the libraries used in the final firmware.

---

## File Structure
```
automated-irrigation/
├── libraries/
│   └── myosa-libraries/
├── sensors-code/
│   └── sensors-code.ino
├── cover.jpeg
├── system-hardware.jpeg
├── sensors.jpeg
├── irrigation-demo.mp4
├── automated-irrigation.md
└── LICENSE
```
## License 

MIT License.


## Contribution Notes 

Contributions, suggestions, and improvements to the project are welcome through issues and pull requests in the project repository.
