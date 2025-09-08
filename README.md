# 7Semi-ADS126x-Arduino-Library

This Arduino library provides unified support for the **7Semi ADS1262 (10-channel)** and **7Semi ADS1263 (32-channel)** 32-bit precision ADC boards via SPI. Both boards are based on the Texas Instruments ADS126x series, ideal for high-resolution, low-noise, and multi-channel analog data acquisition.

![Arduino](https://img.shields.io/badge/platform-arduino-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Status](https://img.shields.io/badge/status-active-brightgreen.svg)

---

## Hardware Supported

- 7Semi ADS1262 10-Channel 32-bit ADC Board  
- 7Semi ADS1263 32-Channel 32-bit ADC Board  

---

## Getting Started

### 1. Installation via Arduino Library Manager

1. Open **Arduino IDE**
2. Go to:
   - `Sketch > Include Library > Manage Libraries…` (IDE 1.x)  
   - or click the 📚 Library Manager icon (IDE 2.x)
3. Search:
   - 7Semi ADS126x
4. Click **Install**

In your sketch:

#include <7semi_ads126x.h>

### 2. Wiring (Default Pins)

| ADS1262 Pin | Arduino Pin |
|-------------|-------------|
| CS          | 7           |
| DRDY        | 6           |
| START       | 5           |
| PWDN        | 4           |
| SCK         | 13 SCK (SPI)|
| MISO        | 12 MISO (SPI)|
| MOSI        | 11 MOSI (SPI)|
| DVDD/AVDD   | 5V          |
| DGND/AGND   | GND         |

### 3. Applications

Industrial instrumentation

Precision weight/load/strain measurement

Scientific sensing and lab equipment

High-channel-count DAQ systems
