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

#include <stdbool.h>

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


int main(void)
{
	DDRD = 255;
	
	int idx = 0;
	bool state = true;
	srand(53543);
	while (1)
	{
		if(state && idx < 150)
		{
			idx++;
		}
		else if(!state)
		{
			idx--;
		}
		
		for(int i = 0; i < idx; i++)
		{
			_delay_ms(1);
		}
		
		if(idx >= 150)
			state = false;
			
		if(idx <= 0)
			state = true;
		
		LED_TOGGLE(PD6);
    }
}

