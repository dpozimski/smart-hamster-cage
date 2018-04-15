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
	private:
		uint8_t buffer[SSD1306_BUFFERSIZE];
		SSD1306Adapter ssd1306;
};


#endif /* OLEDScreen_H_ */