#include <Arduino.h>
#include "Scheduler.h"
#include "ProductSelectionTask.h"
#include "Manifest.h"
#include "ButtonImpl.h"
#include "CoffeDisplay.h"



Scheduler sched;
ProductSelectionTask* psTask;
CoffeDisplay* display;
Manifest* manifest;

void setup() {
  manifest = new Manifest();
  psTask = new ProductSelectionTask(manifest);
  Serial.begin(9600);
  display = new CoffeDisplay();
  display -> printWelcomeMessage();
  psTask -> init(100, display);
  sched.init(100);
  sched.addTask(psTask);
}

void loop() {
  sched.schedule();
}