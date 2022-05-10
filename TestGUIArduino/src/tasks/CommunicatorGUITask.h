#ifndef __COMMUNICATOR__
#define __COMMUNICATOR__
#include "Task.h"
#include "../utils/Manifest.h"

class CommunicatorGUITask: public Task{
public:
    Manifest* manifest;
    String lastMsg;
private:
    CommunicatorGUITask(Manifest* manifest);
    void init(int period);
    void tick();
    void reciveMsg();
    void sendMsg();
};

#endif