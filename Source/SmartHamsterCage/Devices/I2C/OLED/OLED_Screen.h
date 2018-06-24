/*
 * SSD1306.h
 *
 * Created: 15.04.2018 20:27:56
 *  Author: d.pozimski
 */ 


#ifndef OLEDScreen_H_
#define OLEDScreen_H_

#include "./../I2CDevice.h"

#define SSD1306_WIDTH 128
#define SSD1306_HEIGHT 64
#define SSD1306_BUFFERSIZE (SSD1306_WIDTH*SSD1306_HEIGHT) / 8

class OLEDScreen : public I2CDevice
{
	public:
		OLEDScreen();
		void init() override;
        void clearBuffer();
        void drawTitle(const char* text);
        void drawText(uint8_t x, uint8_t y, char* text);
        void flush();
};


#endif /* OLEDScreen_H_ */