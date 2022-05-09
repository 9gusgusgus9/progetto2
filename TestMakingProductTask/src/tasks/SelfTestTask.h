#ifndef __SELF_TEST__
#define __SELF_TEST__
#include "Task.h"
#include "../utils/Manifest.h"

class SelfTestTask: public Task{
public:
    SelfTestTask(Manifest* manifest);
    void init(int period);
    void tick();
    bool selfTest();

private:
    Manifest* manifest;
    bool isTesting;
    bool passedTest;
    bool isTested;
    bool isTimeToTest;
    unsigned long lastTest;
};

#endif