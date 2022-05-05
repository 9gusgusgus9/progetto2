#include "ProductSpillTask.h"
#include "Arduino.h"

ProductSpillTask::ProductSpillTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSpillTask::init(int period, CoffeDisplay* display, ServoMotorImpl* servo){
    Task::init(period);
    this -> display = display;
    this -> servo = servo;
    this -> status = 0;
    this -> lastUpdateStatus = millis();
}

void ProductSpillTask::tick(){
    if(manifest -> getStatus() == Status::MAKING_PROCESS){
        display -> printMakingProcess(this -> manifest -> getLastSpilled(), status);
        if(millis() - lastUpdateStatus > 1000){
            status++;
            servo -> setPosition(servo -> getPosition() + 18);
            lastUpdateStatus = millis();
        }
    if(status > MAX_STATUS){
        manifest -> setStatus(Status::PRODUCT_READY);
        status = 0;
    }
}
}










