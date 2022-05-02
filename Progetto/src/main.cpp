#include <Arduino.h>
#include "Scheduler.h"
#include "ProductSelectionTask.h"
#include "Manifest.h"

Scheduler sched;
ProductSelectionTask* psTask;

void setup() {
  sched.init();
  psTask -> init(100);
  sched.addTask(psTask);
}

void loop() {
  
  sched.schedule();
}