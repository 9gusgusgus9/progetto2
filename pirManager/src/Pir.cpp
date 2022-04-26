#include "Pir.h"
#include "Arduino.h"

Pir::Pir(int pin){
    this -> pin = pin;
    pinMode(pin,INPUT);
    calibrate();
}

void Pir::calibrate(){
    for(int i = 0; i<10;i++){
        delay(1000);
    }
}

int Pir::getState(){
    return digitalRead(pin);
}