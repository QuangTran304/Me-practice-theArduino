/*
    Author: Quang Tran
    Date: July 27, 2019
*/

const int VERTICAL = 1;
const int HORIZONTAL = 0;
const int SELECT = 10;

void setup() {
  pinMode(VERTICAL, INPUT);
  pinMode(HORIZONTAL, INPUT);
  pinMode(SELECT, INPUT);
  Serial.begin(9600);
}

void loop() {
  int vertical_val = analogRead(VERTICAL);
  int horizontal_val = analogRead(HORIZONTAL);
  if (digitalRead(SELECT)) {
    Serial.println(">>> SELECT is clicked <<<");
  }
  Serial.print("Vertical: ");
  Serial.println(vertical_val);
  Serial.print("Horizontal: ");
  Serial.println(horizontal_val);
  delay(200);
}
