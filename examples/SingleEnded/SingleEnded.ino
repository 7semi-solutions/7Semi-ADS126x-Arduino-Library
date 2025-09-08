/*******************************************************
 * @file SingleEnded.ino
 *
 * @brief Example demonstrating single-ended voltage readings
 *        using the 7Semi ADS126x library (ADS1262 / ADS1263).
 *
 * This example shows how to initialize the ADS126x ADC via SPI
 * and perform single-ended measurements from multiple channels.
 *
 * Connections:
 * - DRDY  -> Pin 6
 * - CS    -> Pin 7
 * - START -> Pin 5
 * - PWDN  -> Pin 4
 * - SPI   -> Standard SPI pins (SCK, MISO, MOSI)
 *
 * Notes:
 * - AINCOM (channel 10) is used as the reference for all channels.
 * - Works with both ADS1262 (10CH) and ADS1263 (32CH) boards.
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
  Serial.println("----- Voltage Readings -----");

  // Read all 10 single-ended channels (AIN0–AIN9)
  for (int i = 0; i < 10; i++) {
    float voltage = adc.readSingleEnded(i);
    Serial.print("AIN");
    Serial.print(i);
    Serial.print(" = ");
    Serial.print(voltage, 6);
    Serial.println(" V");
    delay(200);
  }
  delay(2000);
}
