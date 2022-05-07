#ifndef __WELCOME__
#define __WELCOME__

#include "Task.h"
#include "../utils/Manifest.h"

class WelcomeMessageTask: public Task{
    
public:
    WelcomeMessageTask(Manifest* manifest);
    void init();
    void tick();
private:
    Manifest* manifest;
};

#endif