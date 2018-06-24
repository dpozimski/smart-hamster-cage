/*
 * SSD1306_Adapter.cpp
 *
 * Created: 15.04.2018 20:29:26
 *  Author: d.pozimski
 */ 

#define DEFAULT_ADDRESS 0x78

//Additional pins
#define RES_PIN PC4
#define DC_PIN PC3
#define CS_PIN PC2

//Logic constants
#define TITLE_OFFSET_Y 17;

#include <avr/io.h>
#include <string.h>

extern "C"
{
    #include "mk_oled/mk_ssd1306.h"
}

#include "OLED_Screen.h"
#include "./../../../Utils/Bits.h"
#include "./../../ControlLed.h"

OLEDScreen::OLEDScreen() : I2CDevice(DEFAULT_ADDRESS)
{
    DDRC |= (1 << RES_PIN) | (1 << DC_PIN) | (1 << CS_PIN);
    	
    Bits::setPortValue(&PORTC, RES_PIN, 1);
    Bits::setPortValue(&PORTC, DC_PIN, 0);
    Bits::setPortValue(&PORTC, CS_PIN, 1);
}

void OLEDScreen::init()
{
	this->I2CDevice::init();
	mk_ssd1306_init(0, 0, 1);
}

void OLEDScreen::clearBuffer()
{
    mk_ssdD1306_cls();
}

void OLEDScreen::drawTitle(const char *text)
{
    mk_ssd1306_puts(10, 5, (char*)text, 1, 1, 0);
}

void OLEDScreen::drawText(uint8_t x, uint8_t y, char* text)
{
    y += TITLE_OFFSET_Y;
    uint8_t lineHeight = 1;
    uint8_t line = 0;
    char* textPart = strtok(text, "\n");
    while (textPart != NULL) {
        mk_ssd1306_puts(x, y, textPart, lineHeight, 1, 1);
        line++;
        y += (line * lineHeight) + 6;
        textPart = strtok(NULL, "\n");
    }
}    

void OLEDScreen::flush()
{
    mk_ssd1306_display();
}

