#ifndef __COFFE_DISPLAY__
#define __COFFE_DISPLAY__
#include <LiquidCrystal_I2C.h>

class CoffeDisplay{
    LiquidCrystal_I2C* display;

    public:

    CoffeDisplay();
    
    void printMessageGiustify(String first, String second, String third, String fourth);
    void printMessageCentered(String first, String second, String third, String fourth);
    void printWelcomeMessage();
    void printReadyMessage();
    void printAssistanceMessage();
    void printProductReady(String product);
    void printTestMessage();
    void printProductAndSugar(String product, int sugar);
    void printMakingProcess(String product);
};

#endif