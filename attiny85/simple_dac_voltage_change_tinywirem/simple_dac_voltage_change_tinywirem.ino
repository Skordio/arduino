#include <TinyWireM.h>
#include <Adafruit_MCP4725.h>

Adafruit_MCP4725 dac;

void setup(void) {
  TinyWireM.begin();  // Initialize TinyWireM
  // Serial.begin(9600);
  // Serial.println("MCP4725 Test");
  
  dac.begin(0x62);    // MCP4725 address is 0x60 (ADDR pin tied to GND)
}

void loop(void) {
  delay(1000);
  dac.setVoltage((1 * 4095) / 5, false);  // Set voltage to 1V
}
