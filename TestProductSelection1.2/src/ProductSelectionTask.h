#ifndef __PRODUCT_SELECTION__
#define __PRODUCT_SELECTION__
#include "Task.h"
#include "CoffeDisplay.h"
#include "Manifest.h"

class ProductSelectionTask: public Task{
    CoffeDisplay* display;
    Manifest* manifest;
    Product actualProduct;
    int sugar;
    bool isActive;
    
public:
    ProductSelectionTask(Manifest* manifest);
    void init(int period);
    void tick();
    void bUp();
    void bDown();
    void bMake();
    void sugarPot(int pot);
};

#endif