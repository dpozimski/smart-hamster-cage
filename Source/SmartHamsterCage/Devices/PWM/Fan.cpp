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
    //timer is set in StepperMotorClock
}

void Fan::updatePwmRegister()
{
    OCR1B = this->value;
}
