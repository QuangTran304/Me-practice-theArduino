/*
    Author: Quang Tran
    Date: June 8th, 2019

    Note: This is a very simple program that controls a dc motor's speed using a transistor (PWM on Base).
*/


const int MOTOR = 9;

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  for (int i = 0; i < 256; i++) {     // Let the motor runs from slowest to fastest speed.
    analogWrite(MOTOR, i);
    delay(10);
  }
  
  delay(2000);                        // Delay (keep) doing whatever happening for 2 secs.

  for (int i = 255; i >= 0; i--) {    // Let the motor run from fastest to slowest speed.
    analogWrite(MOTOR, i);
    delay(10);
  }

  delay(2000);
}
