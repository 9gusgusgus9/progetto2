#include <Arduino.h>
#include "Sensor.h"
#define ECHO 7
#define TRIG 8

Sensor* sensor;

void setup() {
  Serial.begin(115200);
  sensor = new Sensor(ECHO, TRIG);
}

void loop() {
  Serial.println(sensor -> getDistance());
  delay(100);
}