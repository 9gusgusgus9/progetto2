#include "ButtonImpl.h"
#include "Arduino.h"
#include "Manifest.h"

#define DEBOUNCING_TIME 30

/* ----------------------- ButtonImpl --------------- */

ButtonImpl::ButtonImpl(int pin){
  this->pin = pin;
  pinMode(pin, INPUT);  
  lastEventTime = millis();
} 
  
bool ButtonImpl::isPressed(){
  long curr = millis();
  if (curr - lastEventTime > DEBOUNCING_TIME){
    lastEventTime = curr;
    return digitalRead(pin) == HIGH;
  } else {
    return false;
  }
}

