#include <Arduino.h>
#include "manager/CoffeDisplay.h"
#include "tasks/ProductReadyTask.h"
#include "tasks/ProductSelectionTask.h"
#include "utils/Scheduler.h"
#include "tasks/ProductSpillTask.h"
#include "manager/ServoMotorImpl.h"
#include "tasks/WelcomeMessageTask.h"

Manifest* manifest;
CoffeDisplay* display;
ProductReadyTask* prTask;
ProductSelectionTask* psTask;
ProductSpillTask* spillTask;
Scheduler* scheduler;
ServoMotorImpl* servo;
WelcomeMessageTask* welcomeTask;

void setup() {
  Serial.begin(9600);
  manifest = new Manifest();
  display = new CoffeDisplay();
  psTask = new ProductSelectionTask(manifest);
  prTask = new ProductReadyTask(manifest);
  spillTask = new ProductSpillTask(manifest);
  welcomeTask = new WelcomeMessageTask(manifest);
  scheduler = new Scheduler();
  welcomeTask -> init(100);
  spillTask -> init(100);
  psTask -> init(100);
  prTask -> init(100);
  scheduler -> init();
  scheduler -> addTask(welcomeTask);
  scheduler -> addTask(psTask);
  scheduler -> addTask(prTask);
  scheduler -> addTask(spillTask); 
}

void loop() {
  scheduler -> schedule();
}