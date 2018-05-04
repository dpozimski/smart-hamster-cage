/*
 * I2C.cpp
 *
 * Created: 10.04.2018 19:10:59
 *  Author: d.pozimski
 */ 

#include "I2CDevice.h"

#include "./../../Utils/GlobalDefs.h"
#include <util/delay.h>

extern "C" {
    #include "./Lib/i2c_master.h"
}    

bool I2CDevice::busInitialized = false;

I2CDevice::I2CDevice(uint8_t address) 
{
	this->address = address;
}

void I2CDevice::init()
{
    if(!this->busInitialized)
    {
        i2c_init();
        this->busInitialized = true;
    }
}

bool I2CDevice::writeToRegistry(uint8_t regAddr, uint8_t* data, uint16_t length)
{
    if(i2c_start(this->address))
        return true;          

    if(i2c_write(regAddr))
        return true;

	for (uint16_t i = 0; i < length; i++)
	{
		if (i2c_write(data[i])) 
			return true;
	}

	i2c_stop();

	return false;
}

bool I2CDevice::readFromRegistry(uint8_t regAddr, uint8_t* data, uint16_t length)
{
	if(i2c_start(this->address | I2C_WRITE))
	    return true;

	if(i2c_write(regAddr))
	    return true;
        
    i2c_stop();

	if(i2c_start(this->address | I2C_READ))
	    return true;

	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = i2c_read_ack();
	}
	data[length-1] = i2c_read_nack();

	i2c_stop();

	return false;
}


bool I2CDevice::writeByteToRegistry(uint8_t regAddr, uint8_t data)
{
	if(i2c_start(this->address | I2C_WRITE))
	    return true;

	if(i2c_write(regAddr))
	    return true;

	if(i2c_write(data))
	    return true;

	i2c_stop();

	return false;
}

uint8_t I2CDevice::readByteFromRegistry(uint8_t regAddr)
{
	if(i2c_start(this->address | I2C_WRITE))
	    return true;

	if(i2c_write(regAddr))
	    return true;
	
	i2c_stop();

	if(i2c_start(this->address | I2C_READ))
	    return true;

	uint8_t value = i2c_read_nack();

	i2c_stop();

	return value;
}