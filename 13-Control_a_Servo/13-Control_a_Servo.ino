/*
    Author: Quang Tran
    Date: July 25, 2019
*/

#include <Servo.h>

const int SERVO = 9;
const int POT = 0;

Servo servo1;
int value = 0;

void setup() {
  servo1.attach(SERVO);       // Established servo1
}

void loop() {
  value = analogRead(POT);    // Read and map the value to 0-180 degree
  value = map(value, 0, 1023, 0, 179);
  servo1.write(value);
  delay(5);
}
