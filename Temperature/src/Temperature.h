#ifndef __TEMP__
#define __TEMP__

class Temperature{
    int pin;

    public:

    Temperature(int pin);
    double getTemperature();
    double convertTemperature(double data){
        return (((data)* 0.00488) - 0.5) / 0.01;
    }
};

#endif