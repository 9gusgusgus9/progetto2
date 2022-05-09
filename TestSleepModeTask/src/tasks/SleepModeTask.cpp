#include "SleepModeTask.h"
#include "EnableInterrupt.h"
#include "avr/sleep.h"

SleepModeTask::SleepModeTask(Manifest* manifest){
    this -> manifest = manifest;
}

void SleepModeTask::init(int period){
    Task::init(period);
}

void wakeUp(){}

void SleepModeTask::tick(){
    if(this -> manifest -> getPir() -> getState() == HIGH){
        Serial.println("Detected");
        this -> manifest -> detection();
    } else {
        Serial.println("Not detected");
    }
    if(this -> manifest -> getStatus() == Status::SLEEP_MODE){
        enableInterrupt(PIR, &wakeUp, RISING);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        sleep_disable();
        disableInterrupt(PIR);
        this -> manifest -> setStatus(Status::MACHINE_READY);
    }
}
