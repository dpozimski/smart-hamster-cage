/*
 * I2CDevice.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: d.pozimski
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
	    bool transmit(uint8_t* data, uint16_t length);
		bool receive(uint8_t* data, uint16_t length);
		bool writeToRegistry(uint8_t regAddr, uint8_t* data, uint16_t length);
		bool readFromRegistry(uint8_t regAddr, uint8_t* data, uint16_t length);
		bool writeByteToRegistry(uint8_t regAddr, uint8_t data);
		uint8_t readByteFromRegistry(uint8_t regAddr);
	private:
        bool beginTransmission(bool isWriteMode);
        uint8_t readWithAck();
        uint8_t readWithoutAck();
        bool write(uint8_t data);
        void endTransmission(void);
        void waitForEndOfTransmission();
	    uint8_t address;
        static bool busInitialized;
};

#endif