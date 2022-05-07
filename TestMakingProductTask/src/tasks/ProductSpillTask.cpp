#include "ProductSpillTask.h"
#include "Arduino.h"

ProductSpillTask::ProductSpillTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSpillTask::init(int period){
    Task::init(period);
    this -> manifest -> getServo() -> on();
    this -> manifest -> getServo() -> setPosition(180);
    this -> status = 0;
    this -> lastUpdateStatus = millis();
}

void ProductSpillTask::tick(){
    if(manifest -> getStatus() == Status::MAKING_PROCESS){
        manifest -> getDisplay() -> printMakingProcess(this -> manifest -> getLastSpilled(), status);
        if(millis() - lastUpdateStatus > 1000){
            if(status == 0){
                manifest -> getServo() -> on();
            }
            Serial.println(manifest -> getServo() -> getPosition());
            status++;
            if(manifest -> getServo() -> getPosition() > 0){
                manifest -> getServo() -> setPosition(manifest -> getServo() -> getPosition() - 18);
            }
            lastUpdateStatus = millis();
        }
        if(status > MAX_STATUS){
            manifest -> setStatus(Status::PRODUCT_READY);
            manifest -> getServo() -> off();
            Serial.println(manifest -> getServo() -> getPosition());
            status = 0;
        }
    }
}










