#include <Arduino.h>
#include "MakingProcessTask.h"
#include "Scheduler.h"
#include "CoffeDisplay.h"
#include "Manifest.h"

ServoMotor* schiavo;
CoffeDisplay* display;
Scheduler* scheduler;
MakingProcessTask* task;

void setup() {
  schiavo = new ServoMotor(SERVO);
  display = new CoffeDisplay();
  scheduler = new Scheduler();
  task = new MakingProcessTask(schiavo, display);
  scheduler -> init();
  task -> init(100);
  scheduler -> addTask(task);
}

void loop() {
  scheduler -> schedule();
}