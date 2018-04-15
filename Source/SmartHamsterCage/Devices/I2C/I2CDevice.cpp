/*
 * I2C.cpp
 *
 * Created: 10.04.2018 19:10:59
 *  Author: d.pozimski
 */ 

#define SCL_CLOCK 100000L

#include <util/twi.h>
#include "I2CDevice.h"
#include "./../../GlobalDefs.h"

uint8_t I2CDevice::twi_status_register = 0x00;
bool I2CDevice::busInitialized = false;

I2CDevice::I2CDevice(uint8_t address) 
{
	this->address = address;
}

void I2CDevice::init()
{
    if(!this->busInitialized)
    {
        TWSR = 0;
        TWBR = ((F_CPU/SCL_CLOCK)-16)/2;
        this->busInitialized = true;
    }
}

bool I2CDevice::beginWrite() {
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));

	twi_status_register = TW_STATUS & 0xF8;
	if ((this->twi_status_register != TW_START) && (this->twi_status_register != TW_REP_START)) {
		return true;
	}

	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	this->twi_status_register = TW_STATUS & 0xF8;
	if ((this->twi_status_register != TW_MT_SLA_ACK) && (this->twi_status_register != TW_MR_SLA_ACK)) {
		return true;
	}

	return false;
}

bool I2CDevice::write(uint8_t data) {
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);

	while(!(TWCR & (1<<TWINT)));

	this->twi_status_register = TW_STATUS & 0xF8;
    
	return this->twi_status_register != TW_MT_DATA_ACK;
}

void I2CDevice::endWrite(void) {
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}
