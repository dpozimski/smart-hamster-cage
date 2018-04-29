/*
 * SSD1306_Adapter.cpp
 *
 * Created: 15.04.2018 20:29:26
 *  Author: d.pozimski
 */ 

#define DEFAULT_ADDRESS 0x78

//Commands
#define SETCONTRAST 0x81
#define DISPLAYALLON_RESUME 0xA4
#define DISPLAYALLON 0xA5
#define NORMALDISPLAY 0xA6
#define INVERTDISPLAY 0xA7
#define DISPLAYOFF 0xAE
#define DISPLAYON 0xAF
#define SETDISPLAYOFFSET 0xD3
#define SETCOMPINS 0xDA
#define SETVCOMDETECT 0xDB
#define SETDISPLAYCLOCKDIV 0xD5
#define SETPRECHARGE 0xD9
#define SETMULTIPLEX 0xA8
#define SETLOWCOLUMN 0x00
#define SETHIGHCOLUMN 0x10
#define SETSTARTLINE 0x40
#define MEMORYMODE 0x20
#define COLUMNADDR 0x21
#define PAGEADDR   0x22
#define COMSCANINC 0xC0
#define COMSCANDEC 0xC8
#define SEGREMAP 0xA0
#define CHARGEPUMP 0x8D
#define SWITCHCAPVCC 0x2
#define NOP 0xE3

//Internals
#define SINGLEPACKETCOUNT 16
#define REQPACKETSTOSEND SSD1306_BUFFERSIZE / 16

//Additional pins
#define RES_PIN PC4
#define DC_PIN PC3
#define CS_PIN PC2

#include "SSD1306_Adapter.h"
#include "./../../../Utils/Bits.h"
#include <avr/io.h>

SSD1306Adapter::SSD1306Adapter() : I2CDevice(DEFAULT_ADDRESS)
{
	DDRC |= (1 << RES_PIN) | (1 << DC_PIN) | (1 << CS_PIN);
    
    Bits::setPortValue(&PORTC, RES_PIN, 1);
    Bits::setPortValue(&PORTC, DC_PIN, 0);
    Bits::setPortValue(&PORTC, CS_PIN, 1);
}

void SSD1306Adapter::init()
{
	this->I2CDevice::init();
	
	// Turn display off
    this->sendCommand(DISPLAYOFF);
    this->sendCommand(SETDISPLAYCLOCKDIV);
	this->sendCommand(0x80);
    this->sendCommand(SETMULTIPLEX);
    this->sendCommand(0x3F);    
    this->sendCommand(SETDISPLAYOFFSET);
    this->sendCommand(0x00);    
    this->sendCommand(SETSTARTLINE | 0x00);    
    // We use internal charge pump
    this->sendCommand(CHARGEPUMP);
    this->sendCommand(0x14);    
    // Horizontal memory mode
    this->sendCommand(MEMORYMODE);
    this->sendCommand(0x00); 
    this->sendCommand(SEGREMAP | 0x1);
    this->sendCommand(COMSCANDEC);
    this->sendCommand(SETCOMPINS);
    this->sendCommand(0x12);
    // Max contrast
    this->sendCommand(SETCONTRAST);
    this->sendCommand(0xCF);
    this->sendCommand(SETPRECHARGE);
    this->sendCommand(0xF1);
    this->sendCommand(SETVCOMDETECT);
    this->sendCommand(0x40);
    this->sendCommand(DISPLAYALLON_RESUME);
    // Non-inverted display
    this->sendCommand(NORMALDISPLAY);
    // Turn display back on
    this->sendCommand(DISPLAYON);
}

void SSD1306Adapter::sendFramebuffer(uint8_t *buffer) 
{
	this->sendCommand(COLUMNADDR);
	this->sendCommand(0x00);
	this->sendCommand(SSD1306_WIDTH - 1);

	this->sendCommand(PAGEADDR);
	this->sendCommand(0x00);
	this->sendCommand((SSD1306_HEIGHT / 8) - 1);

	for (uint8_t packetIdx = 0; packetIdx < REQPACKETSTOSEND; packetIdx++)
    {
        uint8_t packet[SINGLEPACKETCOUNT];
		for (uint8_t packet_byte = 0; packet_byte < SINGLEPACKETCOUNT; packet_byte++) 
		{
			packet[packet_byte] = buffer[packetIdx*16+packet_byte];
		}
        this->writeToRegistry(0x40, packet, SINGLEPACKETCOUNT);
	}
}

void SSD1306Adapter::sendCommand(uint8_t command)
{
	this->writeByteToRegistry(0x00, command);
}

