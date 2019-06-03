/*
    Author: Quang Tran
    Date: June 2nd, 2019

    Note: This program will read the analog signal from a photoresistor.
*/

const int photoPin = 0;

void setup() {
  analogReference(DEFAULT);   // 5v reference voltage by default, so this line is not necessary.
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(photoPin));
  delay(500);
}
