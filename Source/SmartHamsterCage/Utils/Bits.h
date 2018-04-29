/*
 * Bits.h
 *
 * Created: 29.04.2018 13:12:08
 *  Author: dpsol
 */ 


#ifndef BITS_H_
#define BITS_H_

#include <stdbool.h>
#include <stdio.h>

class Bits
{
    public:
        static void setPortValue(volatile uint8_t *port, uint8_t pin, bool value);
        static bool readPinValue(volatile uint8_t *port, uint8_t pin);
        static void togglePin(volatile uint8_t *port, uint8_t pin);
    private:
        Bits();    
};


#endif /* BITS_H_ */