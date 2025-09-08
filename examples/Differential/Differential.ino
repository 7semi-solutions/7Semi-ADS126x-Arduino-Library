/*******************************************************
 * @file Differential.ino
 *
 * @brief Example demonstrating differential voltage readings
 *        using the 7Semi ADS126x library (ADS1262 / ADS1263).
 *
 * This example shows how to initialize the ADS126x ADC via SPI
 * and perform differential measurements between analog input channels.
 *
 * Connections:
 * - DRDY  -> Pin 6
 * - CS    -> Pin 7
 * - START -> Pin 5
 * - PWDN  -> Pin 4
 * - SPI   -> Standard SPI pins (SCK, MISO, MOSI)
 *
 * Notes:
 * - AINCOM (channel 10) is used as the common reference.
 * - Compatible with both ADS1262 (10CH) and ADS1263 (32CH).
 *
 * @section author Author
 * Written by 7Semi
 *
 * @section license License
 * @license MIT
 * Copyright (c) 2025 7Semi
 *******************************************************/


#include <7semi_ADS126x.h>

// Default pin configuration
#define DRDY_PIN 6
#define CS_PIN 7
#define START_PIN 5
#define PWDN_PIN 4

// Create ADC object
ADS126x_7semi adc(DRDY_PIN, CS_PIN, START_PIN, PWDN_PIN);

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;
  adc.begin();
  Serial.println("7Semi ADS126x 32bit ADC.");
}

void loop() {
  // Read differential voltage from AIN0–AIN1, AIN2–AIN3, ..., AIN8–AIN9
  for (uint8_t i = 0; i <= 8; i += 2) {
    float voltage = adc.readDifferential(i, i + 1);

    Serial.print("AIN");
    Serial.print(i);
    Serial.print(" - AIN");
    Serial.print(i + 1);
    Serial.print(": ");

    if (!isnan(voltage)) {
      Serial.print(voltage, 6);
      Serial.println(" V");
    } else {
      Serial.println("N/A");
    }
    delay(200);  // Small delay between readings
  }

  Serial.println("-------------\n");
  delay(1000);
}
