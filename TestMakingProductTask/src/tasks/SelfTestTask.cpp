#include "SelfTestTask.h"
#include "Arduino.h"

SelfTestTask::SelfTestTask(Manifest* manifest){
    this -> manifest = manifest;
    this -> isTesting = false;
    this -> passedTest = false;
    this -> isTested = false;
    this -> lastTest = millis();
}

void SelfTestTask::init(int period){
    Task::init(period);
}

void SelfTestTask::tick(){
    if(millis() - this -> lastTest > TtoTest){
        this -> manifest -> setTimeToTest(true);
    }
    if(this -> manifest -> getStatus() == Status::CHECK_TEST){
        if(!this -> isTesting){
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
                this -> isTested = false;
                this -> passedTest = false;
                this -> manifest -> setTimeToTest(false);
                this -> lastTest = millis();
            }
        }
    }
}

bool SelfTestTask::selfTest(){
    this -> isTesting = true;
    for(int i = 180; i > 0; i--){
        this -> manifest -> getServo() -> setPosition(i);
    }
    for(int i = 1; i <= 180; i++){
        this -> manifest -> getServo() -> setPosition(i);
    }

    if(this -> manifest -> getTemperature() < T_MIN || this -> manifest -> getTemperature() > T_MAX){
        this -> isTesting = false;
        return true;
    } else {
        this -> isTesting = false;
        return false;
    }
}