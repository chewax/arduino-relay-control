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
    RelayControl(int pin, String type);
    void open();
    void close();
    void flick();
    bool is_closed();
  private:
    int _pin;
    bool _flow;
    String _type;
};

#endif