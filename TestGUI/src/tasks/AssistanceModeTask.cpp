#include "AssistanceModeTask.h"

AssistanceModeTask::AssistanceModeTask(Manifest* manifest){
    this -> manifest = manifest;
}

void AssistanceModeTask::init(int period){
    Task::init(period);
}

void AssistanceModeTask::tick(){
    if(this -> manifest -> getStatus() == Status::ASSISTANCE_MODE){
        this -> manifest -> getDisplay() -> printAssistanceMessage();
    }
}