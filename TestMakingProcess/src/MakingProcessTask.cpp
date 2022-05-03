#include "MakingProcessTask.h"
#include "Arduino.h"

MakingProcessTask::MakingProcessTask(ServoMotor* servo, CoffeDisplay* display){
    this -> servo = servo;
    this -> isActive = false;
    this -> actualPosition = 0;
    this -> display = display;
    this -> status = 0;
}

void MakingProcessTask::init(int period){
    Task::init(period);
}

void MakingProcessTask::make(Product product, int sugar){
    this -> isActive = true;
    this -> product = product;
    this -> sugar = sugar;
    this -> status++;
    this -> display -> printMakingProcess(product, status);
}

void MakingProcessTask::tick(){
    if(isActive){
        this -> servo -> moveTo(actualPosition);
        this -> actualPosition += 5;
        if(this -> actualPosition % 10 == 0){
            this -> status++;
        }
        this -> display -> printMakingProcess(product, status);
    }
}