#include <Wire.h>
#include <MCP4725.h>

MCP4725 dac;

void setup() {
  Wire.begin();  // Initialize I2C
  Serial.begin(9600);
  Serial.println("MCP4725 Test");
  dac.begin(0x60);  // MCP4725A1 address is 0x60 (ADDR pin tied to GND)
}

void loop() {
  dac.setVoltage((1 * 4095) / 5, false);  // Set voltage to 1V
  delay(1000);
  dac.setVoltage((2 * 4095) / 5, false);  // Set voltage to 2V
  delay(1000);
  dac.setVoltage((3 * 4095) / 5, false);  // Set voltage to 3V
  delay(1000);
  dac.setVoltage((4 * 4095) / 5, false);  // Set voltage to 4V
  delay(1000);
  dac.setVoltage(4095, false);            // Set voltage to 5V or (Vcc)
  delay(1000);
}
