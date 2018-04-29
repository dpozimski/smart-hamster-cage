/*
 * Timer.cpp
 *
 * Created: 19.04.2018 18:17:40
 *  Author: d.pozimski
 */ 

#include "Timer.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define TICKS_TO_SECOND 100

ISR (TIMER0_COMP_vect)
{
    static uint8_t cnt = 0;
    if(cnt++ >= TICKS_TO_SECOND)
    {
        Timer timer;
        timer.incrementElapsedSeconds();
        cnt = 0;   
    }
}

uint32_t Timer::elapsedSeconds = 0;

void Timer::init()
{
    //interrupt each 10ms
    //WGM00 && WGM01 - CTC
    //CS000 && CS01 && CS03 - Prescaller / 1024
    TCCR0 |= (1<<WGM01) | (1<<CS02) | (1<<CS00);
    //to get 100Hz frequency
    OCR0 = 77;
    //enable Compare Math interrupt
    TIMSK |= (1<<OCIE0);
}

uint32_t Timer::getElapsedSeconds()
{
    return this->elapsedSeconds;
}

void Timer::incrementElapsedSeconds()
{
    this->elapsedSeconds++;
}
