#include "ServoMotor.h"
#include "Arduino.h"
#include "ServoTimer2.h"

ServoTimer2 servo;

ServoMotor::ServoMotor(int pin){
    this -> pin = pin;
    servo.attach(pin);
}

void ServoMotor::moveTo(int degree){
    servo.write(degree);
    delay(20);
}

void ServoMotor::goToStart(){
    servo.write(0);
    delay(20);
}

void ServoMotor::goToEnd(){
    servo.write(180);
    delay(20);
}

int ServoMotor::getPosition(){
    return servo.read();
}