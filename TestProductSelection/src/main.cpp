#include <Arduino.h>
#include "Scheduler.h"
#include "ProductSelectionTask.h"
#include "Manifest.h"
#include "async_fsm.h"
#include "ButtonImpl.h"

Scheduler sched;
ProductSelectionTask* psTask;

class ButtonManagerAsyncFSM : public AsyncFSM {
  public:
    ButtonManagerAsyncFSM(Button* button){
      nextTick = STOP;
      this->button = button;
      button->registerObserver(this);
    }
  
    void handleEvent(Event* ev) {
        if (ev->getType() == BUTTON_UP_PRESSED){
          nextTick = UP;
        }
        if (ev->getType() == BUTTON_DOWN_PRESSED){
          nextTick = DOWN;
        }
        if (ev->getType() == BUTTON_MAKE_PRESSED){
          nextTick = MAKE;
        }
      }
  private:
    Button* button;
    enum  { UP, DOWN, MAKE, STOP} nextTick;
};

ButtonManagerAsyncFSM* buttons;

void setup() {
  sched.init();
  psTask -> init(100);
  sched.addTask(psTask);
}

void loop() {
  
  sched.schedule();
}