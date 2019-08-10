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

  digitalWrite(latchPin, LOW);                      // Initially set LOW to store all the bits (Serially)
  shiftOut(dataPin, clockPin, MSBFIRST, B11011001); // We could use LSBFIRST (Least Significant Bit) as well.
  digitalWrite(latchPin, HIGH);                     // Latch set HIGH to output all the received signals (Parallel)
}

void loop() {

}
