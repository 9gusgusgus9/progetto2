#include "Manifest.h"
#include "Arduino.h"

Manifest::Manifest(){
    this -> servo = new ServoMotorImpl(SERVO);
    this -> display = new CoffeDisplay();
    this -> sensor = new Sensor(ECHO, TRIG);
    this -> status = INIT;
}

bool Manifest::isAvailable(Product product){
    switch(product){
        case COFFE:
            return AVIABLE_COFFE - coffeCounter > 0;
        case THE:
            return AVIABLE_THE - theCounter > 0;
        case CHOCOLATE:
            return AVIABLE_CHOCOLATE - chocolateCounter > 0;
    }
}

bool Manifest::someProductAvailable(){
    return isAvailable(COFFE) || isAvailable(THE) || isAvailable(CHOCOLATE);
}

void Manifest::setLastSpilled(Product product){
    switch(product){
        case COFFE:
            coffeCounter++;
            break;
        case THE:
            theCounter++;
            break;
        case CHOCOLATE:
            chocolateCounter++;
            break;
    }
    lastSpilled = product;
}

Product Manifest::getLastSpilled(){
    return this -> lastSpilled;
}

void Manifest::setSugar(int sugar){
    this -> sugar = sugar;
}

int Manifest::getSugar(){
    return this -> sugar;
}

Status Manifest::getStatus(){
    return this -> status;
}

void Manifest::setStatus(Status status){
    Serial.println(status);
    this -> status = status;
}

ServoMotorImpl* Manifest::getServo(){
    return this -> servo;
}

CoffeDisplay* Manifest::getDisplay(){
    return this -> display;
}

Sensor* Manifest::getSensor(){
    return this -> sensor;
}