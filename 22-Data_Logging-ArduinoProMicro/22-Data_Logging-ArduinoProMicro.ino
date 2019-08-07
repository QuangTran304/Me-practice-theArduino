/*
    Author: Quang Tran
    Date: August 6, 2019
*/

#include<Keyboard.h>

const int TEMP = 0;   // A0 pin
const int LIGHT = 1;  // A1 pin
const int LED = 3;
const int BUTTON = 2;

bool lastButton = LOW;
bool currentButton = LOW;
bool running = false;
int counter = 1;

void setup() {
  pinMode(LED, OUTPUT);
  Keyboard.begin();   // Start keyboard emulation
}

void loop() {
  currentButton = findCurrentState(lastButton);
  if (lastButton == LOW  &&  currentButton == HIGH) {
    running = !running;
  }

  lastButton = currentButton;

  if (running) {     // If logger is running
    digitalWrite(LED, HIGH);
    if (millis() % 1000 == 0) {
      int temperature = analogRead(TEMP);
      int brightness = analogRead(LIGHT);
      Keyboard.print(counter);
      Keyboard.print(",");
      Keyboard.print(temperature);
      Keyboard.print(",");
      Keyboard.println(brightness);
      ++counter;
    } else {
      digitalWrite(LED, LOW);
    }
  } 
}

bool findCurrentState(bool prev) {
  int current = digitalRead(BUTTON);
  
  if (current != prev) {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}
