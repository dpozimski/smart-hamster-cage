/*
 * SSD1306.h
 *
 * Created: 15.04.2018 20:27:56
 *  Author: d.pozimski
 */ 


#ifndef SSD1306ADAPTER_H_
#define SSD1306ADAPTER_H_

#include "./../I2CDevice.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_BUFFERSIZE (SSD1306_WIDTH*SSD1306_HEIGHT) / 8

class SSD1306Adapter : public I2CDevice
{
	public:
		SSD1306Adapter();
		void init() override;
		void sendFramebuffer(uint8_t *buffer);
	private:
		void sendCommand(uint8_t command);
};


#endif /* SSD1306ADAPTER_H_ */