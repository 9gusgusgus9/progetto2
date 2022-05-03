#ifndef __MAKING__
#define __MAKING__
#include "ServoMotor.h"
#include "Manifest.h"
#include "Task.h"
#include "CoffeDisplay.h"

class MakingProcessTask: public Task{
public:
    MakingProcessTask(ServoMotor* servo, CoffeDisplay* display);
    void init(int period);
    void make(Product product, int sugar);
    void tick();

private:
    ServoMotor* servo;
    CoffeDisplay* display;
    Product product;
    int sugar;
    bool isActive;
    int actualPosition;
    int status;
};

#endif