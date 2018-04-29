/*
 * ControlLed.cpp
 *
 * Created: 15.04.2018 20:05:50
 *  Author: d.pozimski
 */ 

#define CTRL_LED PC5

#include "ControlLed.h"
#include "./../Utils/Bits.h"
#include "./../Utils/GlobalDefs.h"
#include <avr/io.h>
#include <util/delay.h>

void ControlLed::init()
{
	DDRC |= (1 << PC5);
	this->setValue(false);
}

bool ControlLed::readValue()
{
    return Bits::readPinValue(&PINC, CTRL_LED);
}

void ControlLed::setValue(bool value)
{
    Bits::setPortValue(&PORTC, CTRL_LED, value);
}

void ControlLed::signal()
{
	bool previousValue = this->readValue();
	
	for(uint8_t i = 0; i < 20; i++)
	{
        Bits::togglePin(&PORTC, CTRL_LED);
		_delay_ms(50);
	}
	
	this->setValue(previousValue);
}
