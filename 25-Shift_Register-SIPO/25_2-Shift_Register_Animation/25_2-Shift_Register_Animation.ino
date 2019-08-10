/*
    Author: Quang Tran
    Date: August 9, 2019
*/

unsigned dataPin = 8;
unsigned latchPin = 9;
unsigned clockPin = 10;

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  for (int i = 1; i <= 128; i *= 2) {
    digitalWrite(latchPin, LOW);                 // Initially set LOW to store all the bits (Serially)
    shiftOut(dataPin, clockPin, MSBFIRST, i);    // Use 'i' or we could use an array of predetermined values
    digitalWrite(latchPin, HIGH);                // Latch set HIGH to output all the received signals (Parallel)
    delay(60);
  }
   for (int i = 128; i > 0; i /= 2) {
    digitalWrite(latchPin, LOW);                 
    shiftOut(dataPin, clockPin, MSBFIRST, i);    
    digitalWrite(latchPin, HIGH);               
    delay(60);
  }
}
