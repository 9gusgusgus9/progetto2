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
}

void ServoMotor::goToStart(){
    servo.write(0);
    delay(5000);
    servo.write(90);
    delay(5000);
    servo.write(180);
    delay(5000);
}

void ServoMotor::goToEnd(){
    servo.write(180);
    delay(20);
}

int ServoMotor::getPosition(){
    return servo.read();
}

void ServoMotor::makeCoffe(){
    for(int i = 0; i <= 220; i++){
        servo.write(i);
    }
}

void ServoMotor::turnBack(){
    for(int i = 220; i >= 0; i--){
        servo.write(i);
    }
}