#ifndef __SERVOMOTOR__
#define __SERVOMOTOR__

class ServoMotor{
    int pin;

    public:

    ServoMotor(int pin);
    void moveTo(int degree);
    void goToStart();
    void goToEnd();
    int getPosition();
};

#endif