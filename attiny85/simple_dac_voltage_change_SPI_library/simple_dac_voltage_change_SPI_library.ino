#include <SoftSPI.h>
#include <SoftwareSerial.h>
#include <Wire.h>

// Pin definitions for SoftSPI
#define DAC_MOSI_PIN 0
#define DAC_SCK_PIN  2
#define DAC_CS_PIN   1

// Create SoftSPI instance
SoftSPI<DAC_MOSI_PIN, DAC_SCK_PIN, -1, MSBFIRST, 0> softSPI;

// Serial output for debugging
SoftwareSerial debugSerial(-1, 3); // RX, TX

// Function to set voltage on MCP4725
void setVoltage(uint16_t voltage) {
  digitalWrite(DAC_CS_PIN, LOW);
  softSPI.transfer(64 | (voltage >> 8));
  softSPI.transfer(voltage & 255);
  digitalWrite(DAC_CS_PIN, HIGH);
}

void setup() {
  pinMode(DAC_CS_PIN, OUTPUT);
  digitalWrite(DAC_CS_PIN, HIGH);
  softSPI.begin();

  debugSerial.begin(9600);
  debugSerial.println("MCP4725 Test");
}

void loop() {
  setVoltage((1 * 4095) / 5);  // Set voltage to 1V
  delay(1000);
  setVoltage((2 * 4095) / 5);  // Set voltage to 2V
  delay(1000);
  setVoltage((3 * 4095) / 5);  // Set voltage to 3V
  delay(1000);
  setVoltage((4 * 4095) / 5);  // Set voltage to 4V
  delay(1000);
  setVoltage(4095);            // Set voltage to 5V or (Vcc)
  delay(1000);
}
