#ifndef __MAKING_PRODUCT__
#define __MAKING_PRODUCT__

#define MAX_STATUS 10

#include "Task.h"
#include "Manifest.h"
#include "CoffeDisplay.h"
#include "ServoMotorImpl.h"

class ProductSpillTask: public Task{

public:
    ProductSpillTask(Manifest* manifest);
    void init(int period, CoffeDisplay* display, ServoMotorImpl* servo);
    void tick();

private:
    CoffeDisplay* display;
    Manifest* manifest;
    ServoMotorImpl* servo;
    int status;
    unsigned long lastUpdateStatus;
};

#endif