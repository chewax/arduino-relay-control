#include "Arduino.h"
#include "RelayControl.h"


RelayControl::RelayControl(int pin, char(2) type)
/*
	type:: sets the relay type. "NC" - will set the Relay as Normally Closed type and thus
	the initial state will be "ON" (_state = true). Setting type as "NO" (Normally Opened) will
	set the initial state to "OFF" (_state = false)
*/
{
  pinMode(pin, OUTPUT);
  _pin = pin;
  _state = (type == "NC");
}

void RelayControl::on()
{
	digitalWrite(_pin, HIGH);
	_state = true; //ON
}

void RelayControl::off()
{
	digitalWrite(_pin, LOW);
	_state = false; //OFF
}

void RelayControl::flick()
{
	if (_state)
	{
		digitalWrite(_pin, LOW);
		_state = false; //OFF	
	}
	else
	{
		digitalWrite(_pin, HIGH);
		_state = true; //ON
	}
}

bool RelayControl::is_on()
{
	return _state;
}