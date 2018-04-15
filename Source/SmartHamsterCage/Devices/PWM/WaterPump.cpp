/*
 * Fan.cpp
 *
 * Created: 15.04.2018 13:55:53
 *  Author: dpsol
 */ 

#include "WaterPump.h"
#include <avr/io.h>

void WaterPump::init()
{
    //WGM20 && WGM21 - Fast PWM
    //COM20 && COM21 - Inverting mode
    //CS20 && CS21 && CS23 - Prescaller / 8
    TCCR2 |= (1<<WGM20) | (1<<WGM21) | (1<<COM20) | (1<<COM21) | (1<<CS21);
}

void WaterPump::updatePwmRegister()
{
    OCR2 = this->value;
}
