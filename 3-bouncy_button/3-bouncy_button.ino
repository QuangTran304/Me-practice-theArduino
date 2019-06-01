const int LED = 10;
const int BUTTON = 2;
bool lastButton = LOW;      // Prev. button state
bool currentButton = LOW;   // Current button state
bool ledOn = false;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);  
}


// As long as the button is not pushed, currentButton remains LOW.
// And eventually it will update lastButton = LOW (if not being pushed)
// Which doesn't affect the led's state

// As soon as currentButton is switched to HIGH (being push),
// there's a differenet in states with lastButton,
// ===> Change LED.

void loop() {
  currentButton = findCurrentState(lastButton);     
  if (currentButton == HIGH && lastButton == LOW) {
    ledOn = !ledOn;  
  }
  lastButton = currentButton;
  digitalWrite(LED, ledOn);
}


// This function will make sure that the state of the button is collected correctly.
// Always takes 'current' button no matter what the last is.
bool findCurrentState(bool last) {
  bool current = digitalRead(BUTTON);
  if (last != current) {
    delay(5);           // Wait 5ms for the bouncing signal.
    current = digitalRead(BUTTON);
  }
  return current;
}
