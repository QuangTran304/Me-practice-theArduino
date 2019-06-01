const int LED = 10;
const int BUTTON = 2;
bool state = true;

void setup() {

  pinMode(LED, OUTPUT);       // We can use '1' instead of 'OUTPUT'
  pinMode(BUTTON, INPUT);     // We can use '0' instead of 'INPUT'

}

void loop() {
  
  while (state) {
    if (digitalRead(BUTTON) == 0) {
       digitalWrite(LED, 0);
       state = false;
    }
  }

  if (digitalRead(BUTTON) == 1) {
       digitalWrite(LED, 1);
       state = true;
    }
}
