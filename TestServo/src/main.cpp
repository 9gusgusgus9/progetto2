#include <Arduino.h>
#include "ServoMotorImpl.h"
#include "Timer.h"

int pos;   
int delta;
ServoMotorImpl* pMotor;

void setup() {
  Serial.begin(9600);
  pMotor = new ServoMotorImpl(9);
  pos = 0;
  delta = 1;
}

void loop() {
  pMotor->on();
  for (int i = 0; i < 180; i++) {
    Serial.println(pos);
    pMotor->setPosition(pos);         
    // delay(2);            
    pos += delta;
  }
  pMotor->off();
  pos -= delta;
  delta = -delta;
  //delay(1000);
}