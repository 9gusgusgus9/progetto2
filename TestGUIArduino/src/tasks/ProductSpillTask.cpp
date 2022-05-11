#include "ProductSpillTask.h"
#include "Arduino.h"

ProductSpillTask::ProductSpillTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSpillTask::init(int period){
    Task::init(period);
    this -> manifest -> getServo() -> on();
    this -> manifest -> getServo() -> setPosition(0);
    this -> status = 0;
    this -> lastUpdateStatus = millis();
}

void ProductSpillTask::tick(){
    if(manifest -> getStatus() == Status::MAKING_PROCESS){
        this -> manifest -> detection();
        manifest -> getDisplay() -> printMakingProcess(this -> manifest -> getLastSpilled(), status/2);
        if(millis() - lastUpdateStatus > Tmake/20){
            if(status == 0){
                manifest -> getServo() -> on();
            }
            status++;
            if(manifest -> getServo() -> getPosition() < 180){
                manifest -> getServo() -> setPosition(manifest -> getServo() -> getPosition() + 9);
            }
            lastUpdateStatus = millis();
        }
        if(status > STATUS_MAX){
            this -> manifest -> detection();
            manifest -> setStatus(Status::PRODUCT_READY);
            manifest -> getServo() -> off();
            status = 0;
        }
    }
}










