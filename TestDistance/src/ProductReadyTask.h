#ifndef __PRODUCT_READY__
#define __PRODUCT_READY__
#include "Task.h"
#include "Sensor.h"
#include "Manifest.h"
#include "CoffeDisplay.h"

class ProductReadyTask: public Task{

public:
    ProductReadyTask(Manifest* manifest);
    void init(int echo, int trig, int period, CoffeDisplay* display);
    void tick();
private:
    Sensor* sensor;
    Manifest* manifest;
    int pin;
    bool isTheFirstRound;
    long unsigned timeFromReady;
    int period;
    CoffeDisplay* display;
};

#endif