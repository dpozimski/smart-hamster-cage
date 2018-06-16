/*
 * WaterFeedController.cpp
 *
 * Created: 18.04.2018 21:10:51
 *  Author: d.pozimski
 */ 

#define POUR_PWM_VALUE 28
#define TEMP_EXCEEDED_VALUE 32

#define POUR_CYCLIC_DURATION 175
#define POUR_CYCLIC_DURATION_IF_TEMP_EXCEEDED 110

#define POUR_DURATION 6

#include "WaterFeedController.h"

WaterFeedController::WaterFeedController(WaterPump* waterPump, OutputTimeRule* outputTimeRule)
{
    this->outputTimeRule = outputTimeRule;
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
    this->outputTimeRule->update(elapsedSeconds, POUR_DURATION, getIdleTime(elapsedSeconds));
    
    if(this->outputTimeRule->isOutputShouldBeEnabled() && !this->waterPump->readValue())
    {
        //turn on pouring
        this->waterPump->setValue(POUR_PWM_VALUE);
    }
    else if(!this->outputTimeRule->isOutputShouldBeEnabled() && this->waterPump->readValue())
    {
        //turn off pouring
        this->waterPump->setValue(0);
    }
}

uint8_t WaterFeedController::getIdleTime(uint32_t elapsedSeconds)
{
    uint8_t cyclicDuration = (this->temperature >= TEMP_EXCEEDED_VALUE) ? 
        POUR_CYCLIC_DURATION_IF_TEMP_EXCEEDED : POUR_CYCLIC_DURATION;
        
    return cyclicDuration;
}
