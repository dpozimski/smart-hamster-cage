/*
 * Fan.cpp
 *
 * Created: 15.04.2018 13:55:53
 *  Author: d.pozimski
 */ 

#include "WaterPump.h"
#include <avr/io.h>

void WaterPump::init()
{
    //Set OC2 pin as an output
    DDRD |= (1 << PD7);
    //WGM20 && WGM21 - Fast PWM
    //COM20 && COM21 - Inverting mode
    //CS20 && CS21 && CS22 - Prescaller / 1024
    TCCR2 |= (1<<WGM20) | (1<<WGM21) | (1<<COM20) | (1<<COM21) | (1<<CS20) | (1<<CS21) | (1<<CS22);
}

void WaterPump::updatePwmRegister(uint8_t value)
{
    //decrease precision
    OCR2 = value;
}
