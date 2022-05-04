#ifndef __COFFE_DISPLAY__
#define __COFFE_DISPLAY__
#include <LiquidCrystal_I2C.h>
#include "Manifest.h"

enum LastPrint{
    WELCOME,
    READY,
    ASSISTANCE,
    P_READY,
    TEST,
    SELECT_COFFE,
    SELECT_THE,
    SELECT_CHOCOLATE,
    MAKING
};

class CoffeDisplay{
    LiquidCrystal_I2C* display;
    LastPrint lastPrint;

public:

    CoffeDisplay();
    void printMessageGiustify(String first, String second, String third, String fourth);
    void printMessageCentered(String first, String second, String third, String fourth);
    void printWelcomeMessage();
    void printReadyMessage();
    void printAssistanceMessage();
    void printProductReady(Product product);
    void printTestMessage();
    void printProductAndSugar(Product product, int sugar);
    void printMakingProcess(Product product, int status);
};

#endif