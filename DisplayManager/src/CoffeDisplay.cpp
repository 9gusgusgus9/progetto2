#include "CoffeDisplay.h"
#include "Arduino.h"

byte fullPin[8] = {
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111,
    B11111
};

CoffeDisplay::CoffeDisplay(){
    display = new LiquidCrystal_I2C(0x27, 20, 4);
    display -> init();
    display -> backlight();
}

void CoffeDisplay::printMessageGiustify(String first, String second, String third, String fourth){
    display -> clear();
    display -> setCursor(0,0);
    display -> print(first);
    display -> setCursor(0,1);
    display -> print(second);
    display -> setCursor(0,2);
    display -> print(third);
    display -> setCursor(0,3);
    display -> print(fourth);
}

void CoffeDisplay::printMessageCentered(String first, String second, String third, String fourth){
    display -> clear();
    int cursor = 20;
    cursor -= first.length();
    cursor /= 2;
    display -> setCursor(cursor ,0);
    display -> print(first);
    cursor = 20;
    cursor -= second.length();
    cursor /= 2;
    display -> setCursor(cursor ,1);
    display -> print(second);
    cursor = 20;
    cursor -= third.length();
    cursor /= 2;
    display -> setCursor(cursor ,2);
    display -> print(third);
    cursor = 20;
    cursor -= fourth.length();
    cursor /= 2;
    display -> setCursor(cursor ,3);
    display -> print(fourth);
}

void CoffeDisplay::printWelcomeMessage(){
    printMessageCentered("", "Camera Caffe", "Welcome", "");
}

void CoffeDisplay::printReadyMessage(){
    printMessageCentered("", "Machine ready", "press one button", "");
}

void CoffeDisplay::printAssistanceMessage(){
    printMessageCentered("", "Assistance required", "manage with GUI", "");
}

void CoffeDisplay::printProductReady(String product){
    printMessageCentered("", "Product ready", "take your " + product, "Thanks!");
}
void CoffeDisplay::printTestMessage(){
    printMessageCentered("", "Test in progress", "please wait", "");
    for(int cursor = 5; cursor < 15; cursor++){
        display -> setCursor(cursor, 3);
        display -> write(0);
        delay(1000);
    }

}

void CoffeDisplay::printProductAndSugar(String product, int sugar){
    printMessageGiustify("Product:", product, "Sugar:", "");
    display->createChar(0, fullPin);
    for(int cursor = 0; cursor < sugar; cursor++){
        display -> setCursor(cursor, 3);
        display -> write(0);
    }
}

void CoffeDisplay::printMakingProcess(String product){
    printMessageCentered("", "Preparing " + product, "", "");
    for(int cursor = 5; cursor < 15; cursor++){
        display -> setCursor(cursor, 2);
        display -> write(0);
        delay(1000);
    }
}
