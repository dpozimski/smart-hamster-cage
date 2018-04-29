/*
 * WaterFeedController.cpp
 *
 * Created: 18.04.2018 21:10:51
 *  Author: d.pozimski
 */ 

#define POUR_PWM_VALUE 100
#define POUR_IF_TEMPERATURE_VALUE 32

#define POUR_CYCLIC_DURATION 175
#define POUR_CYCLIC_DURATION_IF_TEMP_EXCEEDED 110

#define POUR_DURATION 3

#include "WaterFeedController.h"

WaterFeedController::WaterFeedController(WaterPump* waterPump)
{
    this->waterPump = waterPump;
    this->waterPump->setValue(0);
}

void WaterFeedController::setTemperature(uint8_t temperature)
{
    this->temperature = temperature;
}

void WaterFeedController::update()
{
    uint32_t elapsedSeconds = this->getElapsedSeconds();
    if(!(elapsedSeconds % this->getDurationOfWaterPouring(elapsedSeconds)) && !this->waterPump->readValue())
    {
        //turn on pouring
        this->waterPump->setValue(POUR_PWM_VALUE);
        this->lastExceededTimeStamp = elapsedSeconds;
    }
    else if(((elapsedSeconds - this->lastExceededTimeStamp) >= POUR_DURATION) && this->waterPump->readValue())
    {
        //turn off pouring
        this->waterPump->setValue(0);
    }
}

uint8_t WaterFeedController::getDurationOfWaterPouring(uint32_t elapsedSeconds)
{
    uint8_t cyclicDuration = (this->temperature >= POUR_IF_TEMPERATURE_VALUE) ? 
        POUR_CYCLIC_DURATION_IF_TEMP_EXCEEDED : POUR_CYCLIC_DURATION;
        
    return cyclicDuration;
}
