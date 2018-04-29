/*
 * I2C.cpp
 *
 * Created: 10.04.2018 19:10:59
 *  Author: d.pozimski
 */ 

#define SCL_CLOCK 100000L
#define I2C_READ 0x01
#define I2C_WRITE 0x00

#include <util/twi.h>
#include "I2CDevice.h"
#include "./../../Utils/GlobalDefs.h"

bool I2CDevice::busInitialized = false;

I2CDevice::I2CDevice(uint8_t address) 
{
	this->address = address << 1;
}

void I2CDevice::init()
{
    if(!this->busInitialized)
    {
        //init bus
        TWSR = 0;
        TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
        this->busInitialized = true;
    }
}

bool I2CDevice::transmit(uint8_t* data, uint16_t length)
{
	if (this->beginTransmission(true))
		return true;
	
	for (uint16_t i = 0; i < length; i++)
	{
		if (this->write(data[i]))
			return true;
	}
	
	this->endTransmission();
	
	return false;
}

bool I2CDevice::receive(uint8_t* data, uint16_t length)
{
	if (this->beginTransmission(false))
		return true;
	
	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = this->readWithAck();
	}
	data[(length-1)] = this->readWithoutAck();
	
	this->endTransmission();
	
	return false;
}

bool I2CDevice::writeToRegistry(uint8_t regAddr, uint8_t* data, uint16_t length)
{
	if (this->beginTransmission(true)) 
		return true;

	this->write(regAddr);

	for (uint16_t i = 0; i < length; i++)
	{
		if (this->write(data[i])) 
			return true;
	}

	this->endTransmission();

	return false;
}

bool I2CDevice::readFromRegistry(uint8_t regAddr, uint8_t* data, uint16_t length)
{
	if (this->beginTransmission(true)) 
		return true;

	this->write(regAddr);

	if (this->beginTransmission(false))
		return true;

	for (uint16_t i = 0; i < (length-1); i++)
	{
		data[i] = this->readWithAck();
	}
	data[length-1] = this->readWithoutAck();

	this->endTransmission();

	return false;
}


bool I2CDevice::writeByteToRegistry(uint8_t regAddr, uint8_t data)
{
	if (this->beginTransmission(true))
		return true;

	this->write(regAddr);
	this->write(data);

	this->endTransmission();

	return false;
}

uint8_t I2CDevice::readByteFromRegistry(uint8_t regAddr)
{
	if (this->beginTransmission(true))
		return -1;

	this->write(regAddr);

	if (this->beginTransmission(false))
		return -1;

	uint8_t value = this->readWithoutAck();

	this->endTransmission();

	return value;
}

/* True if error has been occured */
bool I2CDevice::beginTransmission(bool isWriteMode) 
{
    // reset TWI control register
    TWCR = 0;
    // transmit START condition
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    this->waitForEndOfTransmission();

    // check if the start condition was successfully transmitted
    if((TWSR & 0xF8) != TW_START)
        return true;

    // load slave address into data register
    TWDR = isWriteMode ? (address | I2C_WRITE) : (address | I2C_READ);
    // transmission of address
    TWCR = (1<<TWINT) | (1<<TWEN);
    this->waitForEndOfTransmission();

    // check if the device has acknowledged the READ / WRITE mode
    uint8_t twst = TW_STATUS & 0xF8;
    return (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK);
}

uint8_t I2CDevice::readWithAck()
{
    // start TWI module and acknowledge data after reception
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
    this->waitForEndOfTransmission();
    // return received data from TWDR
    return TWDR;
}

uint8_t I2CDevice::readWithoutAck()
{
    // receive without acknowledging reception
    TWCR = (1<<TWINT) | (1<<TWEN);
    this->waitForEndOfTransmission();
    // return received data from TWDR
    return TWDR;
}

/* True if error has been occured */
bool I2CDevice::write(uint8_t data) 
{
    // load data into data register
    TWDR = data;
    // transmission of data
    TWCR = (1<<TWINT) | (1<<TWEN);
    this->waitForEndOfTransmission();
    // check if the device transmitted the data
    return (TWSR & 0xF8) != TW_MT_DATA_ACK;
}

void I2CDevice::endTransmission(void) 
{
	// transmit STOP condition
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
    // wait for end of stop transmission
	while(TWCR & (1<<TWSTO));
}

void I2CDevice::waitForEndOfTransmission()
{
    while( !(TWCR & (1<<TWINT)) );
}
