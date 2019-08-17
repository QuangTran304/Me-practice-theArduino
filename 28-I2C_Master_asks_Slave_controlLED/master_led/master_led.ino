/*
  Author: Quang Tran
  Date: August 17, 2019
*/

#include <Wire.h>

#define SLAVE_ADDR 9
int pot = 0;      // Potentiometer pin
int val = 0;

void setup() {
  Wire.begin();
}

void loop() {
  delay(50);      // Either need it here or at the end of loop() to smooth out communication
  val = map(analogRead(pot), 0, 1023, 0, 255);    
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(val);
  Wire.endTransmission();
}
