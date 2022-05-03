#include <Arduino.h>
#include "Scheduler.h"
#include "ProductSelectionTask.h"
#include "Manifest.h"
#include "ButtonImpl.h"
#include "CoffeDisplay.h"



Scheduler sched;
ProductSelectionTask* psTask;
CoffeDisplay* display;

void setup() {
  display = new CoffeDisplay();
  display -> printWelcomeMessage();
  psTask -> init(100, display);
  sched.init();
  sched.addTask(psTask);
}

void loop() {
  sched.schedule();
}