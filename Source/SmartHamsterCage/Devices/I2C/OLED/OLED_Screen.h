/*
 * OLEDScreen.h
 *
 * Created: 15.04.2018 21:24:21
 *  Author: d.pozimski
 */ 


#ifndef OLEDSCREEN_H_
#define OLEDSCREEN_H_

#include "./../../Device.h"
#include "SSD1306_Adapter.h"

class OLEDScreen : public Device
{
	public:
		void init() override;
		void clearBuffer();
		void drawText(uint8_t x, uint8_t y, char* text);
		void flush();
	private:
		void inline drawInternal(int16_t xMove, int16_t yMove, int16_t width, int16_t height, const uint8_t *data, uint16_t offset, uint16_t bytesInData);
		void drawTextInternal(int16_t xMove, int16_t yMove, char* text, uint16_t textLength, uint16_t textWidth);
	    uint16_t getStringWidth(const char* text, uint16_t length);
		static const uint8_t* fontData;
		uint8_t buffer[SSD1306_BUFFERSIZE];
		SSD1306Adapter ssd1306;
};


#endif /* OLEDScreen_H_ */