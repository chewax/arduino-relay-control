/*
  RelayControl.h - Library for controlling a module for a standard
  digital relay. Daniel Waksman, November 16th 2014. GPL License
*/
#ifndef RelayControl_h
#define RelayControl_h

#include "Arduino.h"

class RelayControl
{
  public:
    RelayControl(int pin, char(2) type);
    void on();
    void off();
    void flick();
    bool is_on();
  private:
    int _pin;
    bool _state;
};

#endif