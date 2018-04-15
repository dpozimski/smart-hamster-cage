/*
 * ControlLed.cpp
 *
 * Created: 15.04.2018 20:05:50
 *  Author: d.pozimski
 */ 

#define CTRL_LED PC5

#include "ControlLed.h"
#include "./../GlobalDefs.h"
#include <avr/io.h>
#include <util/delay.h>

void ControlLed::init()
{
	DDRC |= (1 << PC5);
	this->setValue(false);
}

bool ControlLed::readValue()
{
	return bit_is_set(PINC, CTRL_LED);
}

void ControlLed::setValue(bool value)
{
	PORTC &= ~(value << CTRL_LED);
}

void ControlLed::signal()
{
	bool previousValue = this->readValue();
	
	for(uint8_t i = 0; i < 20; i++)
	{
		PORTC ^= (1 << CTRL_LED);
		_delay_ms(50);
	}
	
	this->setValue(previousValue);
}
