#ifndef __PRODUCT_SELECTION__
#define __PRODUCT_SELECTION__
#include "Task.h"
#include "CoffeDisplay.h"
#include "Manifest.h"
#include "ButtonImpl.h"
#include "SugarPot.h"

class ProductSelectionTask: public Task{
    
    
public:
    ProductSelectionTask(Manifest* manifest);
    void init(int period, CoffeDisplay* display);
    void tick();
    void bUp();
    void bDown();
    void bMake();
    int sugarPot();
    
private:
    CoffeDisplay* display;
    Manifest* manifest;
    Product actualProduct;
    int sugar;
    bool isActive;
    ButtonImpl* bUP, *bDOWN, *bMAKE;
    SugarPot* potSugar;
};

#endif