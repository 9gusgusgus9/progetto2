#ifndef __PIR__
#define __PIR__

class Pir {
    int pin;

    public:

    Pir(int pin);
    void calibrate();
    int getState();

};

#endif