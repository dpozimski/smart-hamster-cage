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
        /************************************************************************/
        /* Creates a new instance of the I2CDevice with address                 */
        /************************************************************************/
	    I2CDevice(uint8_t address);
        /************************************************************************/
        /* Initializes I2C bus of uC                                            */
        /************************************************************************/
        void init() override;
	protected:
        /************************************************************************/
        /* Writes data to selected registry                                     */
        /************************************************************************/
		bool writeToRegistry(uint8_t regAddr, uint8_t* data, uint16_t length);
        /************************************************************************/
        /* Reads [length] bytes from registry to data buffer                    */
        /************************************************************************/
		bool readFromRegistry(uint8_t regAddr, uint8_t* data, uint16_t length);
        /************************************************************************/
        /* Writes single byte to registry                                       */
        /************************************************************************/
		bool writeByteToRegistry(uint8_t regAddr, uint8_t data);
        /************************************************************************/
        /* Reads single byte from registry                                      */
        /************************************************************************/
		uint8_t readByteFromRegistry(uint8_t regAddr);
	private:
	    uint8_t address;
        static bool busInitialized;
};

#endif