/*
    Author: Quang Tran
    Date: August 8, 2019

    Note: This program will lock the computer automatically whenever the light is turned off.
*/

#include <Keyboard.h>

const int SENSOR = 0;           // Photoresistor input to A0

void setup() {
  pinMode(SENSOR, INPUT);
  Keyboard.begin();
}

void loop() {
  int val = analogRead(SENSOR);
  if (val < 600) {                    // Need to do 'Serial...' test to find out the appropriate value.
    Keyboard.press(KEY_LEFT_GUI);     // Command key on Mac
    Keyboard.press(KEY_LEFT_CTRL);    // Left Control key
    Keyboard.press('q');              // Letter 'q' key
    delay(100);
    Keyboard.releaseAll();
  }
}
