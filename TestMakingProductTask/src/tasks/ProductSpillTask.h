#ifndef __MAKING_PRODUCT__
#define __MAKING_PRODUCT__

#define MAX_STATUS 20

#include "Task.h"
#include "../utils/Manifest.h"

class ProductSpillTask: public Task{

public:
    ProductSpillTask(Manifest* manifest);
    void init(int period);
    void tick();

private:
    Manifest* manifest;
    int status;
    unsigned long lastUpdateStatus;
};

#endif