#include "ProductSelectionTask.h"
#include "ButtonImpl.h"

ProductSelectionTask::ProductSelectionTask(Manifest* manifest){
    this -> manifest = manifest;
}

void ProductSelectionTask::init(int period, CoffeDisplay* display){
    Task::init(period);
    this -> actualProduct = COFFE;
    this -> sugar = 1;
    this -> display = display;
    this -> isActive = true;
    this -> bUP = new ButtonImpl(BUP);
    this -> bDOWN = new ButtonImpl(BDOWN);
    this -> bMAKE = new ButtonImpl(BMAKE);
    this -> potSugar = new SugarPot(POT);
    
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

int ProductSelectionTask::sugarPot(){
    return this -> potSugar -> getSugarValue();
}

void ProductSelectionTask::tick(){
    if(this -> bUP -> isPressed()){
        this -> bUp();
    } else if(this -> bDOWN -> isPressed()){
        this -> bDown();
    } else if(this -> bMAKE -> isPressed()){
        this -> bMake();
    }
    int actual = sugarPot();
    if(sugar != actual){
        sugar = actual;
    }
    if(isActive){
        display -> printProductAndSugar(actualProduct, sugar);
    }
}