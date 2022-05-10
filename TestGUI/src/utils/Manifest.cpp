#include "Manifest.h"

Manifest::Manifest(){
    this -> servo = new ServoMotorImpl(SERVO);
    this -> display = new CoffeDisplay();
    this -> sensor = new Sensor(ECHO, TRIG);
    this -> temperature = new Temperature(TEMP);
    this -> status = INIT;
    this -> testToSleep = false;
    this -> testCounter = 0;
}

bool Manifest::isAvailable(Product product){
    switch(product){
        case COFFE:
            return AVIABLE_COFFE - coffeCounter > 0;
        case THE:
            return AVIABLE_THE - theCounter > 0;
        case CHOCOLATE:
            return AVIABLE_CHOCOLATE - chocolateCounter > 0;
        default: 
            return true;
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

bool Manifest::isTestBeforeSleep(){
    return this -> testToSleep;
}

double Manifest::getTemperature(){
    return this -> temperature -> getTemperature();
}

bool Manifest::timeToTest(){
    return this -> isTimeToTest;
}

void Manifest::setTimeToTest(bool value){
    if(value){
        testCounter++;
    }
    this -> isTimeToTest = value;
}

String Manifest::msgToSend(){
    return "" + String(AVIABLE_COFFE - this -> coffeCounter) + "," + String(AVIABLE_THE - this -> theCounter) + "," + String(AVIABLE_CHOCOLATE - this -> chocolateCounter) + "," + String(this -> testCounter);
}

void Manifest::refill(){
    this -> chocolateCounter = 0;
    this -> coffeCounter = 0;
    this -> theCounter = 0;
}