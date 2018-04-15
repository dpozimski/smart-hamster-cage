/*
 * PWMDevice.cpp
 *
 * Created: 15.04.2018 13:46:23
 *  Author: dpsol
 */ 

#include "PWMDevice.h"

void PWMDevice::setValue(uint8_t value)
{
    this->value = value;
    this->updatePwmRegister();
}

uint8_t PWMDevice::readValue()
{
    return this->value;
}
