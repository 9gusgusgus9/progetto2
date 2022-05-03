#ifndef __MANIFEST__
#define __MANIFEST__
#define Tback 5000
#define AVIABLE_COFFE 50
#define AVIABLE_THE 50
#define AVIABLE_CHOCOLATE 50
#define BUP 4
#define BDOWN 2
#define BMAKE 3
#define POT 14


enum Product {
    COFFE,
    THE,
    CHOCOLATE
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
    int coffeCounter = 0;
    int theCounter = 0;
    int chocolateCounter = 0;
    Product lastSpilled;
    int sugar;

public:
    Manifest();
    bool coffeIsAviable();
    bool theIsAviable();
    bool chocolateIsAviable();
    void setLastSpilled(Product prod);
    Product getLastSpilled();
    void setSugar(int sugar);
    int getSugar();
};

#endif