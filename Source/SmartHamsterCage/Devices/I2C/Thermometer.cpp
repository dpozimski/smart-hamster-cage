/*
 * Thermometer.cpp
 *
 * Created: 17.04.2018 18:27:48
 *  Author: dpsol
 */ 

#define DEFAULT_ADDRESS 0x48
#define ACCESS_CONFIG      0xAC
#define START_CONVERT      0xEE
#define READ_TEMPERATURE   0xAA
#define ONE_SHOT           0x01
#define DONE               0x80

#include "Thermometer.h"

Thermometer::Thermometer() : I2CDevice(DEFAULT_ADDRESS)
{
    
}

void Thermometer::init()
{
    this->I2CDevice::init();
    
}
