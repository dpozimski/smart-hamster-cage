/*
 * I2CDevice.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: dpsol
 */ 

#ifndef _I2C_H_
#define _I2C_H_

#include "./../Device.h"
#include <stdbool.h>
#include <stdint.h>

class I2CDevice : Device {
	public:
	    I2CDevice(uint8_t address);
        void init() override;
	protected:
	    bool write(uint8_t data);
        bool beginWrite();
        void endWrite(void);
	private:
	    uint8_t address;
	    static uint8_t twi_status_register;
        static bool busInitialized;
};

#endif