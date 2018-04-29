/*
 * PWMDevice.cpp
 *
 * Created: 15.04.2018 13:46:23
 *  Author: d.pozimski
 */ 

#include "PWMDevice.h"

#define BITS_IN_UINT16 16

void PWMDevice::setValue(uint8_t value)
{
    this->value = value;
    this->updatePwmRegister(~value);
}

uint8_t PWMDevice::readValue()
{
    return this->value;
}
