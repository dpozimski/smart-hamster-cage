/*
 * Fan.cpp
 *
 * Created: 15.04.2018 13:55:53
 *  Author: dpsol
 */ 

#include "StepperMotorClock.h"
#include <avr/io.h>

void StepperMotorClock::init()
{
    //WGM10 && WGM12 - Fast PWM
    //COM1A1 && COM1A0 && COM1B1 && COM1B0 - Inverting mode
    //CS12 && CS11 && CS10 - Prescaller / 1024
    TCCR1A =  (1 << WGM10) | (1<<COM1A1) | (1<<COM1A0) | (1<<COM1B1) | (1<<COM1B0);
    TCCR1B =  (1 << WGM12) | (1<<CS12) | (1<<CS10);
}

void StepperMotorClock::updatePwmRegister()
{
    OCR1A = this->value;
}
