#ifndef __MANIFEST__
#define __MANIFEST__
#define Tback 5000
#define AVIABLE_COFFE 50
#define AVIABLE_THE 50
#define AVIABLE_CHOCOLATE 50
#define BUP 1
#define BDOWN 2
#define BMAKE 3
#define POT A0


enum Product {
    COFFE,
    THE,
    CHOCOLATE
};

inline const char* ToString(Product prod){
    switch(prod){
        case COFFE: return "Coffe";
        case THE: return "The";
        case CHOCOLATE: return "Chocolate";
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
    virtual bool coffeIsAviable() = 0;
    virtual bool theIsAviable() = 0;
    virtual bool chocolateIsAviable() = 0;
    virtual void setLastSpilled(Product prod) = 0;
    virtual Product getLastSpilled() = 0;
    virtual void setSugar(int sugar) = 0;
    virtual int getSugar() = 0;
};

#endif