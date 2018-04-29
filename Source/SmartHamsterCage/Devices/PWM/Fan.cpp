/*
 * Fan.cpp
 *
 * Created: 15.04.2018 13:55:53
 *  Author: d.pozimski
 */ 

#include "Fan.h"
#include <avr/io.h>

void Fan::init()
{
    /* PWM mode etc is set in StepperMotorClock */
    //Set OC1A pin as an output
    DDRD |= (1 << PD4);
    //COM1B1 && COM1B0 - Inverting mode
    TCCR1A |= (1<<COM1B1) | (1<<COM1B0);
}

void Fan::updatePwmRegister(uint8_t value)
{
    OCR1B = value;
}
