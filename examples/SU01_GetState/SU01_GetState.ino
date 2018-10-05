/*************************************************************
  This is an example for the SU01
  Universal Digital Input

  You can buy one on our store!
  -----> https://xinabox.cc/products/SU01/

  This example determines the input state.

  The sensor communicates over the I2C Bus.

*************************************************************/

#include <xCore.h>
#include <xSU01.h>

xSU01 SU01;

void setup() {
  // Start the Serial Monitor
  Serial.begin(115200);

  Wire.begin();

  // Set the I2C Pins for CW01
#ifdef ESP8266
  Wire.pins(2, 14);
  Wire.setClockStretchLimit(15000);
#endif

  // Start the  SU02 Sensor
  SU01.begin();
}

void loop() {

  SU01.poll();

  if (SU01.getState()) {
    Serial.println("button pressed");
  } else {
    Serial.println("nothing new");
  }

  delay(1000);
}
