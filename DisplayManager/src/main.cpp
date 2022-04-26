#include <Arduino.h>
#include "CoffeDisplay.h"

CoffeDisplay* display;

void setup() {
  display = new CoffeDisplay();
  display -> printMakingProcess("Chocolate");
}

void loop() {
}