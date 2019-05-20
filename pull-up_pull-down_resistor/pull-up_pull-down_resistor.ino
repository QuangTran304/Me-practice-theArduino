const int LED = 10;
const int BUTTON = 2;

void setup() {

  pinMode(LED, OUTPUT);       // We can use '1' instead of 'OUTPUT'
  pinMode(BUTTON, INPUT);     // We can use '0' instead of 'INPUT'

}

void loop() {

  if (digitalRead(BUTTON) == LOW) {   // Eq. to '0'
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);          // Eq. to '1'
  }
  
}
