#include "ProductSelectionTask.h"
#include "EnableInterrupt.h"

ProductSelectionTask::ProductSelectionTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSelectionTask::init(int period){
    Task::init(period);
    this -> actualProduct = COFFE;
    this -> sugar = 1;
    this -> display = new CoffeDisplay();
    this -> isActive = true;
}

void ProductSelectionTask::bUp(){
    switch(actualProduct){
        case COFFE:
            actualProduct = CHOCOLATE;
            break;
        case THE:
            actualProduct = COFFE;
            break;
        case CHOCOLATE:
            actualProduct = THE;
            break;
    }
}

void ProductSelectionTask::bDown(){
    switch(actualProduct){
        case COFFE:
            actualProduct = THE;
            break;
        case THE:
            actualProduct = CHOCOLATE;
            break;
        case CHOCOLATE:
            actualProduct = COFFE;
            break;
    }
}

void ProductSelectionTask::bMake(){
    this -> isActive = false;
    display -> printMakingProcess(actualProduct);
}

void ProductSelectionTask::sugarPot(int pot){
    if(pot < 10){
        sugar = 1;
    } else if(pot < 20){
        sugar = 2;
    } else if(pot < 30){
        sugar = 3;
    } else if(pot < 40){
        sugar = 4;
    } else if(pot < 50){
        sugar = 5;
    } else if(pot < 60){
        sugar = 6;
    } else if(pot < 70){
        sugar = 7;
    } else if(pot < 80){
        sugar = 8;
    } else if(pot < 90){
        sugar = 9;
    } else if(pot < 100){
        sugar = 10;
    }
}

void ProductSelectionTask::tick(){
    if(isActive){
        display -> printProductAndSugar(actualProduct, sugar);
    }
}