/*
    Author: Quang Tran
    Date: June 2nd, 2019

    Note: This program will read a value from the potentiometer every 500ms
*/

const int poten = 0;
int value = 0;

void setup() {
  pinMode(poten, INPUT);
  Serial.begin(9600);
}

void loop() {
  value = analogRead(poten);
  Serial.println(value);
  delay(500);  
}
