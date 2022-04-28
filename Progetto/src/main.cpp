#include <Arduino.h>
#include "Scheduler.h"

Scheduler sched;

void setup() {
  sched.init();

}

void loop() {
  sched.schedule();
}