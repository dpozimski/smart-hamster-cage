/*
 * FanController.cpp
 *
 * Created: 18.04.2018 21:07:12
 *  Author: d.pozimski
 */ 

#include "FanController.h"

#define TEMP_WITH_MAX_FAN_SPEED 30
#define HIGHEST_ALLOWED_TEMP 26
#define LOWER_RANGE_HYSTHERESIS 24
#define HYSTHERESIS_SECONDS 60

#define LOWEST_PWM_VALUE 50
#define HIGHEST_PWM_VALUE 255

FanController::FanController(Fan* fan)
{
    this->fan = fan;
    this->fan->setValue(0);
}

void FanController::setTemperature(uint8_t temperature)
{
    this->temperature = temperature;
}

void FanController::update()
{
    if(this->temperature >= HIGHEST_ALLOWED_TEMP)
    {
        this->lastExceededTimeStamp = this->getElapsedSeconds();
        uint8_t pwmValue = this->getPwmValueFromTemperature();
        this->fan->setValue(pwmValue);
    }
    else if(((this->getElapsedSeconds() - this->lastExceededTimeStamp) < HYSTHERESIS_SECONDS) && 
            (this->temperature >= LOWER_RANGE_HYSTHERESIS))
    {
        this->fan->setValue(LOWEST_PWM_VALUE);
    }
    else
    {
        this->fan->setValue(0);
    }
}

uint8_t FanController::getPwmValueFromTemperature()
{
    //set arguments for linear function
    int32_t y2 = HIGHEST_PWM_VALUE, y1 = LOWEST_PWM_VALUE;
    int32_t x2 = TEMP_WITH_MAX_FAN_SPEED, x1 = HIGHEST_ALLOWED_TEMP;
    //linear function
    int32_t y = ( ((y2 - y1)/(x2 - x1)) * this->temperature ) + ( ((x2 * y1) - (x1 * y2)) / (x2 - x1) ); 
    //check higher limit
    if(y > HIGHEST_PWM_VALUE)
        y = HIGHEST_PWM_VALUE;
    return y;
}
