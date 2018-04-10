#ifndef _I2C_H_
#define _I2C_H_

#include <stdbool.h>

class I2CDevice {
	public:
	I2CDevice(uint8_t address);
	bool beginWrite();
	void endWrite(void);
	protected:
	bool write(uint8_t data);
	private:
	uint8_t address;
	uint8_t twi_status_register;
};

#endif