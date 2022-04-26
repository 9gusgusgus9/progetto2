#define PIN 6
#include <Arduino.h>
#include "ServoMotor.h"

ServoMotor* motor;
int i = 0;
boolean increase = true;

void setup() {
  Serial.begin(9600);
  motor = new ServoMotor(PIN);
}

void loop() {
  motor -> moveTo(i);
  
  Serial.println(motor -> getPosition());
  if(i == 180){
    increase = false;
  } else if(i == 0){
    increase = true;
  }
  if(increase){
    i++;
  } else {
    i--;
  }
}