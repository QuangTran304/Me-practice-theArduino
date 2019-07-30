/*
    Author: Quang Tran
    Date: July 30, 2019
*/

char data;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    
    data = Serial.read();
    if (data == '1') {
      
      digitalWrite(LED, HIGH);
      Serial.println("LED on");
      
    } else if (data == '0') {
      
      digitalWrite(LED, LOW);
      Serial.println("LED off");
    } 
  }
}
