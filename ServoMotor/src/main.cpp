#define PIN 9
#include <Arduino.h>
#include "ServoMotor.h"

ServoMotor* motor;
int i = 0;
bool increase = true;
int c = 0;

void setup() {
  Serial.begin(9600);
  motor = new ServoMotor(PIN);
  
}

void loop() {
  motor -> makeCoffe();
  delay(1000);
  motor -> turnBack();
  delay(1000);
}