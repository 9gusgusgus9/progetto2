#ifndef __BUTTON__
#define __BUTTON__

#include "async_fsm.h"

#define BUTTON_UP_PRESSED 1
#define BUTTON_DOWN_PRESSED 2
#define BUTTON_MAKE_PRESSED 3

class Button : public EventSource {
public: 
  virtual bool isPressed() = 0;
};

class ButtonUp: public Event {
public:
  ButtonUp(Button* source) : Event(BUTTON_UP_PRESSED){
    this->source = source;  
  } 
 
  Button* getSource(){
    return source;
  } 
private:
  Button* source;  
};

class ButtonDown: public Event {
public:
  ButtonDown(Button* source) : Event(BUTTON_DOWN_PRESSED){
    this->source = source;  
  } 
 
  Button* getSource(){
    return source;
  } 
private:
  Button* source;  
};

#endif
