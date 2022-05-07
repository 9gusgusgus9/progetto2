#include <Arduino.h>
#include "manager/CoffeDisplay.h"
#include "tasks/ProductReadyTask.h"
#include "tasks/ProductSelectionTask.h"
#include "utils/Scheduler.h"
#include "tasks/ProductSpillTask.h"
#include "manager/ServoMotorImpl.h"

Manifest* manifest;
CoffeDisplay* display;
ProductReadyTask* prTask;
ProductSelectionTask* psTask;
ProductSpillTask* spillTask;
Scheduler* scheduler;
ServoMotorImpl* servo;

void setup() {
  Serial.begin(9600);
  manifest = new Manifest();
  display = new CoffeDisplay();
  psTask = new ProductSelectionTask(manifest);
  prTask = new ProductReadyTask(manifest);
  spillTask = new ProductSpillTask(manifest);
  scheduler = new Scheduler();
  spillTask -> init(100, display);
  psTask -> init(100, display);
  prTask -> init(ECHO, TRIG, 100, display);
  scheduler -> init();
  scheduler -> addTask(psTask);
  scheduler -> addTask(prTask);
  scheduler -> addTask(spillTask); 
}

void loop() {
  scheduler -> schedule();
}