#ifndef __PRODUCT_SELECTION__
#define __PRODUCT_SELECTION__
#include "Task.h"
#include "CoffeDisplay.h"
#include "Manifest.h"
#include "ButtonImpl.h"

class ProductSelectionTask: public Task{
    
    
public:
    ProductSelectionTask(Manifest* manifest);
    void init(int period, CoffeDisplay* display);
    void tick();
    void bUp();
    void bDown();
    void bMake();
    void sugarPot(int pot);
    
private:
    CoffeDisplay* display;
    Manifest* manifest;
    Product actualProduct;
    int sugar;
    bool isActive;
    ButtonImpl* bUP, *bDOWN, *bMAKE;
};

#endif