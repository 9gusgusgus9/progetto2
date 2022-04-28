#include <Arduino.h>
#include "BlinkTask.h"
#include "Scheduler.h"

Scheduler sched;

void setup() {
  sched.init();

  Task* t0 = new BlinkTask(13);
  t0 -> init(500);
  sched.addTask(t0);

  Task* t1 = new BlinkTask(12);
  t1->init(100);
  sched.addTask(t1);

}

void loop() {
  sched.schedule();
}