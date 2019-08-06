/*
    Author: Quang Tran
    Date: August 6, 2019

    Note: This program takes input from the serial monitor to adjust the RGB LED
    Inputs can be separated by commas or spaces.
*/

const int RED = 11;
const int GREEN = 10;
const int BLUE = 9;

int rval = 0;
int gval = 0;
int bval = 0;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  while(Serial.available() > 0) {
    rval = Serial.parseInt();
    gval = Serial.parseInt();
    bval = Serial.parseInt();

    if (Serial.read() == '\n') {
      analogWrite(RED, rval);
      analogWrite(GREEN, gval);
      analogWrite(BLUE, bval);
    }
  }
}
