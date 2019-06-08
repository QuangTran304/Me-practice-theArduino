/*
    Author: Quang Tran
    Date: June 2nd, 2019

    Note: This program will let us change the brightness of an led using a photoresistor.
*/

const int photoPin = 0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(photoPin, INPUT);
}


void loop() {
  
  int value = analogRead(photoPin);
  value = constrain(value, 200, 800);               // Constrain the values to range 200-800 only. Ignore anything else.
  int brightness = map(value, 200, 800, 255, 0);    // Map 200-800 to 255-0 (inversely)
  analogWrite(ledPin, brightness);

    
/*  This part will be used to simply turn the LED on/off  */
//  if (value < 800) {          // Turn the LED on if value from the photoresistor < 800
//    digitalWrite(ledPin, HIGH);
//  } else {                    // Turn it off it value from the photoresistor >= 800
//    digitalWrite(ledPin, LOW);
//  }
}
