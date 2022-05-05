#include <Arduino.h>
#include "CoffeDisplay.h"
#include "ProductReadyTask.h"
#include "ProductSelectionTask.h"
#include "Scheduler.h"
#include "ProductSpillTask.h"
#include "ServoMotorImpl.h"

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
  servo = new ServoMotorImpl(SERVO);
  spillTask -> init(100, display, servo);
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