#include <Arduino.h>
#include "manager/CoffeDisplay.h"
#include "tasks/ProductReadyTask.h"
#include "tasks/ProductSelectionTask.h"
#include "utils/Scheduler.h"
#include "tasks/ProductSpillTask.h"
#include "manager/ServoMotorImpl.h"
#include "tasks/WelcomeMessageTask.h"
#include "tasks/AssistanceModeTask.h"
#include "tasks/SelfTestTask.h"

Manifest* manifest;
ProductReadyTask* prTask;
ProductSelectionTask* psTask;
ProductSpillTask* spillTask;
Scheduler* scheduler;
ServoMotorImpl* servo;
WelcomeMessageTask* welcomeTask;
AssistanceModeTask* assTask;
SelfTestTask* testTask;


void setup() {
  Serial.begin(9600);
  manifest = new Manifest();
  psTask = new ProductSelectionTask(manifest);
  prTask = new ProductReadyTask(manifest);
  spillTask = new ProductSpillTask(manifest);
  welcomeTask = new WelcomeMessageTask(manifest);
  assTask = new AssistanceModeTask(manifest);
  testTask = new SelfTestTask(manifest);
  scheduler = new Scheduler();
  welcomeTask -> init(100);
  spillTask -> init(100);
  psTask -> init(100);
  prTask -> init(100);
  assTask -> init(100);
  testTask -> init(1000);
  scheduler -> init();
  scheduler -> addTask(welcomeTask);
  scheduler -> addTask(psTask);
  scheduler -> addTask(prTask);
  scheduler -> addTask(spillTask);
  scheduler -> addTask(assTask);
  scheduler -> addTask(testTask);
}

void loop() {
  scheduler -> schedule();
}