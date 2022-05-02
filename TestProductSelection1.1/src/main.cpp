#include <Arduino.h>
#include "Scheduler.h"
#include "ProductSelectionTask.h"
#include "Manifest.h"
#include "ButtonImpl.h"

class MyListener : public ButtonListener {
public:
  MyListener(ProductSelectionTask* psTask){
      this -> psTask = psTask;
  }

  void notifyButtonUpPressed(){
    this -> psTask -> bUp();
  }

  void notifyButtonDownPressed(){
    this -> psTask -> bDown();
  }


  void notifyButtonMakePressed(){
    this -> psTask -> bMake(); 
  }

private:
  ProductSelectionTask* psTask;
};

Scheduler sched;
ProductSelectionTask* psTask;
AbstractButton* buttonUp, *buttonDown, *buttonMake;
MyListener* listener;

void setup() {
  sched.init();
  buttonUp = new ButtonImpl(BUP);
  buttonDown = new ButtonImpl(BDOWN);
  buttonMake = new ButtonImpl(BMAKE);
  psTask -> init(100);
  listener = new MyListener(psTask);
  sched.addTask(psTask);
}

void loop() {
  sched.schedule();
}