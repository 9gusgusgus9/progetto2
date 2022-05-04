#include <Arduino.h>
#include "CoffeDisplay.h"
#include "ProductReadyTask.h"
#include "ProductSelectionTask.h"
#include "Scheduler.h"

Manifest* manifest;
CoffeDisplay* display;
ProductReadyTask* prTask;
ProductSelectionTask* psTask;
Scheduler* scheduler;

void setup() {
  Serial.begin(9600);
  manifest = new Manifest();
  display = new CoffeDisplay();
  psTask = new ProductSelectionTask(manifest);
  prTask = new ProductReadyTask(manifest);
  scheduler = new Scheduler();
  psTask -> init(100, display);
  prTask -> init(ECHO, TRIG, 100, display);
  scheduler -> init();
  scheduler -> addTask(psTask);
  scheduler -> addTask(prTask);
}

void loop() {
  scheduler -> schedule();
}