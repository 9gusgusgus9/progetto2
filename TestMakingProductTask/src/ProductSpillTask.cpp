#include "ProductSpillTask.h"
#include "Arduino.h"

ProductSpillTask::ProductSpillTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSpillTask::init(int period, CoffeDisplay* display, ServoMotorImpl* servo){
    Task::init(period);
    this -> display = display;
    this -> servo = servo;
    this -> servo -> on();
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
        servo -> on();
        for(int i = 180; i > 0; i--){
            servo -> setPosition(i);
        }
        servo -> off();
        status = 0;
    }
}
}










