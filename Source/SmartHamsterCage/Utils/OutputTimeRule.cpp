/*
 * OutputController.cpp
 *
 * Created: 29.04.2018 14:53:34
 *  Author: d.pozimski
 */ 

#include "OutputTimeRule.h"

void OutputTimeRule::update(uint32_t elapsedSeconds, uint16_t onDuration, uint16_t offDuration)
{
    if((elapsedSeconds - this->outputWasDisabledTimeStamp) > offDuration && !shouldBeEnabled)
    {
        this->shouldBeEnabled = true;
        this->outputWasActivatedTimeStamp = elapsedSeconds;
    }
    else if((elapsedSeconds - this->outputWasActivatedTimeStamp) > onDuration && shouldBeEnabled)
    {
        this->shouldBeEnabled = false;
        this->outputWasDisabledTimeStamp = elapsedSeconds;
    }
}

bool OutputTimeRule::isOutputShouldBeEnabled()
{
    return this->shouldBeEnabled;
}
