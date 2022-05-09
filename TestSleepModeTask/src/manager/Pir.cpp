#include "Pir.h"
#include "Arduino.h"

Pir::Pir(int pin){
    this -> pin = pin;
    pinMode(pin,INPUT);
    this -> timeInit = millis();
    calibrate();
}

void Pir::calibrate(){
    while(millis() - this -> timeInit < CALIBRATING_TIME){}
}

int Pir::getState(){
    return digitalRead(pin);
}