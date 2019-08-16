/*
    Author: Quang Tran
    Date: August 16, 2019
*/

unsigned dataPin = 8;
unsigned latchPin = 9;
unsigned clockPin = 10;
bool directionState = true;


// 16-bit word = 00000000  00000000
//              High byte  Low Byte

void updateShiftRegister(unsigned leds, bool isMSBFIRST = true) {
  byte lowLED = lowByte(leds);
  byte highLED = highByte(leds);

  digitalWrite(latchPin, LOW);                          // Leave LATCH off so that we could store the data
  if (isMSBFIRST == false) {
    shiftOut(dataPin, clockPin, LSBFIRST, lowLED);      // LSB goes from RIGHT to LEFT. So, we need to 
    shiftOut(dataPin, clockPin, LSBFIRST, highLED);     // go from lowByte to highByte.
  } else {
    shiftOut(dataPin, clockPin, MSBFIRST, highLED);     // MSB goes from LEFT to RIGHT.
    shiftOut(dataPin, clockPin, MSBFIRST, lowLED);      // ==> highByte to lowByte.
  }
  digitalWrite(latchPin, HIGH);                         // Turn LATCH on to 'release' all the bits
}



void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // To CLEAR the LEDs - not necessary
//  unsigned leds = 0B0000000000000000;
//  updateShiftRegister(leds);
//  delay(100);

  for (int i = 1; i < 16; ++i) {
      unsigned leds = 0B0000000000000000;
      bitSet(leds, i);
      updateShiftRegister(leds, directionState);
      delay(120);
  }

  directionState = !directionState;     // Change the LED direction to opposite.
}
