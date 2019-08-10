/*
    Author: Quang Tran
    Date: August 9, 2019
*/

unsigned IRsensor = 0;
unsigned dataPin = 8;
unsigned latchPin = 9;
unsigned clockPin = 10;

// Figure out these numbers by using Mac's programmer calculator
int vals[9] = {0,1,3,7,15,31,63,127,255}; // The values when convert to binary (represent on bargraph LEDs) will have a "battery percentage" effect
int maxDist = 150;
int minDist = 600;

void setup() {
  pinMode(IRsensor, INPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  int distance = analogRead(IRsensor);
  distance = map(distance, maxDist, minDist, 0, 8);   // Map to 9 predetermined values
  distance = constrain(distance, 0, 8);               // Constrain the values in case there's a value above 8 or below 0 
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, vals[distance]);
  digitalWrite(latchPin, HIGH);
  delay(10);
}
