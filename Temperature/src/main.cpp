#define PIN A1
#include <Arduino.h>
#include "Temperature.h"

Temperature* temp;

void setup() {
  Serial.begin(115200);
  temp = new Temperature(PIN);
}

void loop() {
  Serial.println(temp -> getTemperature());
  delay(1000);
}