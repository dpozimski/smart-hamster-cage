/*
 * Thermometer.cpp
 *
 * Created: 17.04.2018 18:27:48
 *  Author: d.pozimski
 */ 

#define DEFAULT_ADDRESS			0x90
#define ACCESS_CONFIG			0xAC
#define START_CONVERT			0xEE
#define READ_TEMPERATURE		0xAA
#define ONE_SHOOT				0x01
#define DONE					0x80

#include "Thermometer.h"

Thermometer::Thermometer() : I2CDevice(DEFAULT_ADDRESS)
{
    
}

void Thermometer::init()
{
    this->I2CDevice::init();
	
	//configure module
	uint8_t config = this->readByteFromRegistry(ACCESS_CONFIG) | ONE_SHOOT;
	this->writeByteToRegistry(ACCESS_CONFIG, config);
}

float Thermometer::getTemperature()
{
	//start converting temperature
	this->writeToRegistry(START_CONVERT, nullptr, 0);
	uint8_t config = 0;
	//wait for conversion
	do 
	{
		config = this->readByteFromRegistry(ACCESS_CONFIG);
	} while ((config & DONE) == 0);
	//read temperature
	uint8_t value = this->readByteFromRegistry(READ_TEMPERATURE);
	return value;
}
