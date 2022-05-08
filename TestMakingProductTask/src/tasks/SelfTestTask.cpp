#include "SelfTestTask.h"

SelfTestTask::SelfTestTask(Manifest* manifest){
    this -> manifest = manifest;
    this -> isTesting = false;
    this -> passedTest = false;
    this -> isTested = false;
}

void SelfTestTask::init(int period){
    Task::init(period);
}

void SelfTestTask::tick(){
    if(this -> manifest -> getStatus() == Status::CHECK_TEST){
        if(!this -> isTesting){
            this -> isTesting = true;
            this -> passedTest = this -> selfTest();
        } else {
            if(this -> isTested){
                if(this -> passedTest){
                    if(manifest -> isTestBeforeSleep()){
                        this -> manifest -> setStatus(Status::SLEEP_MODE);
                    } else {
                        this -> manifest -> setStatus(Status::MACHINE_READY);
                    }
                } else {
                    this -> manifest -> setStatus(Status::ASSISTANCE_MODE);
                }
            }
        }
    }
}

bool SelfTestTask::selfTest(){
    return true;
}