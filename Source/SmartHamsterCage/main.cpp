/*
 * Source.cpp
 *
 * Created: 30.03.2018 15:06:01
 * Author : d.pozimski
 */ 

#define F_CPU 8000000

#define LED_ON(pin) PORTD |= (1 << pin)
#define LED_OFF(pin) PORTD &= ~(1 << pin)
#define LED_TOGGLE(pin) PORTD ^= (1 << pin)

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 255;
	
    while (1) 
    {
		_delay_ms(16);
		LED_TOGGLE(PD6);
    }
}

