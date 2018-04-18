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
    //WGM00 && WGM01 - Fast PWM
    //COM00 && COM01 - Inverting mode
    //CS000 && CS01 && CS03 - Prescaller / 8
    TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM00) | (1<<COM01) | (1<<CS01);
}

void Fan::updatePwmRegister()
{
    OCR0 = this->value;
}
