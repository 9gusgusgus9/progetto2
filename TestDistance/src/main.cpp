#include <Arduino.h>
#include "Scheduler.h"
#include "ProductReadyTask.h"
#include "Manifest.h"
#include "CoffeDisplay.h"

Manifest* manifest;
Scheduler* scheduler;
ProductReadyTask* prTask;
CoffeDisplay* display;

void setup() {
  Serial.begin(9600);
  scheduler = new Scheduler();
  display = new CoffeDisplay();
  manifest = new Manifest();
  prTask = new ProductReadyTask(manifest);
  prTask -> init(ECHO, TRIG, 100, display);
  manifest -> setStatus(Status::PRODUCT_READY);
  manifest -> setLastSpilled(Product::CHOCOLATE);
  scheduler -> init();
  scheduler -> addTask(prTask);
}

void loop() {
  scheduler -> schedule();
}