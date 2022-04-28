#ifndef __MANIFEST__
#define __MANIFEST__
#define Tback 5000
#define AVIABLE_COFFE 50
#define AVIABLE_THE 50
#define AVIABLE_CHOCOLATE 50

enum Product {
    COFFE,
    THE,
    CHOCOLATE
};

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