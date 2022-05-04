#include "ProductReadyTask.h"
#include "Arduino.h"

ProductReadyTask::ProductReadyTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductReadyTask::init(int echo, int trig, int period, CoffeDisplay* display){
    this -> sensor = new Sensor(echo, trig);
    this -> isTheFirstRound = true;
    this -> period = period;
    this -> display = display;
}

void ProductReadyTask::tick(){
    Serial.println(sensor -> getDistance());
    if(this -> manifest -> getStatus() == Status::PRODUCT_READY){
        this -> display -> printProductReady(this -> manifest -> getLastSpilled());
        if(isTheFirstRound){
            isTheFirstRound = false;
            timeFromReady = millis();
        }
        if(this -> sensor -> getDistance() >= 0.40 || millis() - timeFromReady > TtoTake){
            this -> manifest -> setStatus(Status::MACHINE_READY);
        }
    }
}