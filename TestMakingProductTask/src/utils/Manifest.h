#ifndef __MANIFEST__
#define __MANIFEST__

#define Tback 5000
#define TtoTake 40000
#define AVIABLE_COFFE 50
#define AVIABLE_THE 50
#define AVIABLE_CHOCOLATE 50
#define BUP 4
#define BDOWN 2
#define BMAKE 3
#define POT 14
#define ECHO 7
#define TRIG 8
#define SERVO 9

#include "../manager/ServoMotorImpl.h"
#include "../manager/CoffeDisplay.h"
#include "../manager/Sensor.h"

enum Status{
    INIT,
    MACHINE_READY,
    PRODUCT_SUGAR_SELECTION,
    MAKING_PROCESS,
    PRODUCT_READY,
    COME_BACK,
    ASSISTANCE_MODE,
    CHECK_TEST,
    SLEEP_MODE
};

inline const char* toString(Product prod){
    switch(prod){
        case COFFE: return "Coffe";
        case THE: return "The";
        case CHOCOLATE: return "Chocolate";
        default: return "";
    }
}

class Manifest{
    CoffeDisplay* display;
    int coffeCounter = 0;
    int theCounter = 0;
    int chocolateCounter = 0;
    Product lastSpilled;
    int sugar;
    Status status;
    ServoMotorImpl* servo;
    CoffeDisplay* display;
    Sensor* sensor;


public:
    Manifest();
    bool coffeIsAviable();
    bool theIsAviable();
    bool chocolateIsAviable();
    void setLastSpilled(Product prod);
    Product getLastSpilled();
    void setSugar(int sugar);
    int getSugar();
    Status getStatus();
    void setStatus(Status status);
    ServoMotorImpl* getServo();
    CoffeDisplay* getDisplay();
    Sensor* getSensor();
};

#endif