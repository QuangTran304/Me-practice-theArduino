/*
    Author: Quang Tran
    Date: June 3rd, 2019

    Note: This program ... Chip used: LM35 temperature sensor
    About the formula & the number:
        (The attached diagram will show this idea, resolution points, clearly)
        10 bits ADC == 5V  -->  5/1024 = 0.0048828125 V  for each bit/ point of resolution.
        
        0.0000V -> 0b0000000000     ===  0
        0.0048V -> 0b0000000001     ===  1
        ...
        5.0000V -> 0b1111111111     === 1023
        
        Datasheet: 10 mV = 1 *C  OR  0.010 V = 1 *C  
        For each point of resolution (1 bit), the equivalent temperature = 0.0048828125 / 0.010
*/

const int RED = 9;
const int GREEN = 10;
const int BLUE = 11;
const int TEMPERATURE = 0;

void setup() {
  pinMode(TEMPERATURE, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float data = analogRead(TEMPERATURE);
  float temperatureNOW = data * 0.48828125;

  if (temperatureNOW > 30) {          // It's HOT - led turns red
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);
  } else if (temperatureNOW < 18) {   // It's COLD - led turns blue
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, HIGH);
  } else {                            // Comfy temp - led turns green
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, HIGH);
    digitalWrite(BLUE, LOW);
  }
  
  Serial.print("Current temperature: ");
  Serial.println(temperatureNOW);
  delay(1000);
}
