#include "SugarPot.h"
#include "Manifest.h"
#include "Arduino.h"

SugarPot::SugarPot(int pin){
    this -> pin = pin;
    pinMode(pin, INPUT);
}

int SugarPot::getSugarValue(){
    int pot = getValue();
    if(pot < 205){
        return 1;
    } else if(pot < 410){
        return 2;
    } else if(pot < 615){
        return 3;
    } else if(pot < 820){
        return 4;
    } else if(pot < 1024){
        return 5;
    }
}

int SugarPot::getValue(){
    return analogRead(pin);
}