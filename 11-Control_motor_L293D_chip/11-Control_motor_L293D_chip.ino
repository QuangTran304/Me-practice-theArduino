const int EN = 9;
const int MC1 = 3;
const int MC2 = 2;
const int POT = 0;

int val = 0;
int rate = 0;

void forward(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  
  digitalWrite(EN, HIGH);
  analogWrite(EN, rate);
}

void reverse(int rate) {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);

  digitalWrite(EN, HIGH);
  analogWrite(EN, rate);
}

void brake() {
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  analogWrite(EN, HIGH);
}

void setup() {
  pinMode(EN, OUTPUT);
  pinMode(MC1, OUTPUT);
  pinMode(MC2, OUTPUT);
  brake();
}

void loop() {
  val = analogRead(POT);

  if (val > 562) {        // Go forward
    rate = map(val, 563, 1023, 0, 255);
    forward(rate);
  } else if (val < 462) { // Go backward
    rate = map(val, 461, 0, 0, 255);
    reverse(rate);
  } else {                // Break
    brake();
  }
}
