/*
 * Bits.cpp
 *
 * Created: 29.04.2018 13:14:27
 *  Author: dpsol
 */ 

#include "Bits.h"
#include <avr/io.h>

void Bits::setPortValue(volatile uint8_t *port, uint8_t pin, bool value)
{
    if(value)
    {
        *port |= (1 << pin);
    }
    else
    {
        *port &= ~(1 << pin);
    }
}

bool Bits::readPinValue(volatile uint8_t *port, uint8_t pin)
{
	return bit_is_set(*port, pin);
}

void Bits::togglePin(volatile uint8_t *port, uint8_t pin)
{
    *port ^= (1 << pin);
}
