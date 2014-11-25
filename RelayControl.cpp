#include "Arduino.h"
#include "RelayControl.h"

RelayControl::RelayControl(int pin, String type)
/*
	type:: sets the relay type. "NC" - will set the Relay as Normally Closed, and thus
	the initial state will be "Closed" (_flow = true). Setting type as "NO" (Normally Opened) will
	set the initial state to "Open" (_flow = false)
*/
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _flow = (type == "NC");
  _type = type;
}

void RelayControl::open()
/* 
	Opens the relay. No matter what type it is, the function always stops the 
	current flow.
*/
{	
	if (_type == "NC")
	{
		digitalWrite(_pin, HIGH);
		_flow = false; //ON
	}
	else
	{
		digitalWrite(_pin, LOW);
		_flow = false; //ON	
	}
}

void RelayControl::close()
/* 
	Closes the relay. No matter what type it is, the function always starts the 
	current flow.
*/
{
	if (_type == "NC")
	{
		digitalWrite(_pin, LOW);
		_flow = true; //ON
	}
	else
	{
		digitalWrite(_pin, HIGH);
		_flow = true; //ON	
	}
}

void RelayControl::flick()
/* 
	Turns ON if it is OFF and viceversa
*/
{
	if (_flow)
	{
		open();	
	}
	else
	{
		close();
	}
}

bool RelayControl::is_closed()
/* 
	Returns True if current is flowing.
*/
{
	if (_flow){
		Serial.println("Relay is closed --> Current is flowing");
	}else{
		Serial.println("Relay is open --> Current is not flowing");
	}
	return _flow;
}