#define PIN 5
#include <Arduino.h>
#include "Pir.h"

Pir* pir;
int current;
int lastState;

void setup() {
  Serial.begin(9600);
  Serial.println("Calibrating");
  pir = new Pir(PIN);
  Serial.println("Calibrated");
  lastState = false;
}

void loop() {
  current = pir -> getState();
  if(current != lastState){
    if(current){
      Serial.println("Detected");
    } else {
      Serial.println("Not detected");
    }
    lastState = current;
  }
}