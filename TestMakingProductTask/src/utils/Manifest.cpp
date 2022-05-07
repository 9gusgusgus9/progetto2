#include "Manifest.h"

Manifest::Manifest(){
    this -> servo = new ServoMotorImpl(SERVO);
    this -> display = new CoffeDisplay();
}

bool Manifest::coffeIsAviable(){
    return AVIABLE_COFFE - this ->coffeCounter > 0;
}

bool Manifest::theIsAviable(){
    return AVIABLE_THE - this ->theCounter > 0;
}

bool Manifest::chocolateIsAviable(){
    return AVIABLE_CHOCOLATE - this ->chocolateCounter > 0;
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
    this -> status = status;
}

ServoMotorImpl* Manifest::getServo(){
    return this -> servo;
}
CoffeDisplay* Manifest::getDisplay(){
    return this -> display;
}