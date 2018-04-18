/*
 * OLEDScreen.cpp
 *
 * Created: 15.04.2018 21:28:17
 *  Author: d.pozimski
 */ 

#define JUMPTABLE_BYTES 4

#define JUMPTABLE_LSB   1
#define JUMPTABLE_SIZE  2
#define JUMPTABLE_WIDTH 3
#define JUMPTABLE_START 4

#define WIDTH_POS 0
#define HEIGHT_POS 1
#define FIRST_CHAR_POS 2
#define CHAR_NUM_POS 3

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#include "OLED_Screen.h"
#include "OLED_Fonts.h"

#include <string.h>
#include <math.h>

const uint8_t* OLEDScreen::fontData = ArialMT_Plain_10;

void OLEDScreen::init()
{
	this->ssd1306.init();
}

void OLEDScreen::clearBuffer()
{
	memset(buffer, 0, SSD1306_BUFFERSIZE);
}

void OLEDScreen::flush()
{
	this->ssd1306.sendFramebuffer(buffer);
}

void OLEDScreen::drawText(uint8_t x, uint8_t y, char* text)
{
	uint8_t lineHeight = pgm_read_byte(fontData + HEIGHT_POS);

	uint8_t line = 0;
	char* textPart = strtok(text, "\n");
	while (textPart != NULL) {
		uint8_t length = strlen(textPart);
		this->drawTextInternal(x, y + (line++) * lineHeight, textPart, length, getStringWidth(textPart, length));
		textPart = strtok(NULL, "\n");
	}
}

uint16_t OLEDScreen::getStringWidth(const char* text, uint16_t length) 
{
	uint16_t firstChar = pgm_read_byte(fontData + FIRST_CHAR_POS);

	uint16_t stringWidth = 0;
	uint16_t maxWidth = 0;

	while (length--) 
	{
		stringWidth += pgm_read_byte(fontData + JUMPTABLE_START + (text[length] - firstChar) * JUMPTABLE_BYTES + JUMPTABLE_WIDTH);
		if (text[length] == 10)
	    {
			maxWidth = MAX(maxWidth, stringWidth);
			stringWidth = 0;
		}
	}

	return MAX(maxWidth, stringWidth);
}

void OLEDScreen::drawTextInternal(int16_t xMove, int16_t yMove, char* text, uint16_t textLength, uint16_t textWidth) 
{
	uint8_t textHeight       = pgm_read_byte(fontData + HEIGHT_POS);
	uint8_t firstChar        = pgm_read_byte(fontData + FIRST_CHAR_POS);
	uint16_t sizeOfJumpTable = pgm_read_byte(fontData + CHAR_NUM_POS)  * JUMPTABLE_BYTES;
	uint8_t cursorX = 0;

	// Don't draw anything if it is not on the screen.
	if (xMove + textWidth  < 0 || xMove > SSD1306_WIDTH ) 
		return;
	if (yMove + textHeight < 0 || yMove > SSD1306_WIDTH ) 
		return;

	for (uint16_t j = 0; j < textLength; j++) 
	{
		int16_t xPos = xMove;
		int16_t yPos = yMove;

		uint8_t code = text[j];
		if (code >= firstChar) 
		{
			uint8_t charCode = code - firstChar;

			// 4 Bytes per char code
			uint8_t msbJumpToChar    = pgm_read_byte( fontData + JUMPTABLE_START + charCode * JUMPTABLE_BYTES );                  // MSB  \ JumpAddress
			uint8_t lsbJumpToChar    = pgm_read_byte( fontData + JUMPTABLE_START + charCode * JUMPTABLE_BYTES + JUMPTABLE_LSB);   // LSB /
			uint8_t charByteSize     = pgm_read_byte( fontData + JUMPTABLE_START + charCode * JUMPTABLE_BYTES + JUMPTABLE_SIZE);  // Size
			uint8_t currentCharWidth = pgm_read_byte( fontData + JUMPTABLE_START + charCode * JUMPTABLE_BYTES + JUMPTABLE_WIDTH); // Width

			// Test if the char is drawable
			if (!(msbJumpToChar == 255 && lsbJumpToChar == 255)) 
			{
				// Get the position of the char data
				uint16_t charDataPosition = JUMPTABLE_START + sizeOfJumpTable + ((msbJumpToChar << 8) + lsbJumpToChar);
				drawInternal(xPos, yPos, currentCharWidth, textHeight, fontData, charDataPosition, charByteSize);
			}

			cursorX += currentCharWidth;
		}
	}
}

void inline OLEDScreen::drawInternal(int16_t xMove, int16_t yMove, int16_t width, int16_t height, const uint8_t *data, uint16_t offset, uint16_t bytesInData)
{
	if (width < 0 || height < 0) 
		return;
	if (yMove + height < 0 || yMove > SSD1306_HEIGHT)  
		return;
	if (xMove + width  < 0 || xMove > SSD1306_WIDTH)   
		return;

	uint8_t  rasterHeight = 1 + ((height - 1) >> 3);
	int8_t   yOffset      = yMove & 7;

	bytesInData = bytesInData == 0 ? width * rasterHeight : bytesInData;

	int16_t initYMove   = yMove;
	int8_t  initYOffset = yOffset;


	for (uint16_t i = 0; i < bytesInData; i++) 
	{
		// Reset if next horizontal drawing phase is started.
		if ( i % rasterHeight == 0) 
		{
			yMove   = initYMove;
			yOffset = initYOffset;
		}

		uint8_t currentByte = pgm_read_byte(data + offset + i);

		int16_t xPos = xMove + (i / rasterHeight);
		int16_t yPos = ((yMove >> 3) + (i % rasterHeight)) * SSD1306_WIDTH;

		int16_t dataPos    = xPos  + yPos;

		if (dataPos >= 0 && dataPos < SSD1306_BUFFERSIZE && xPos >= 0 && xPos < SSD1306_WIDTH) 
		{
			if (yOffset >= 0) 
			{
				buffer[dataPos] |= currentByte << yOffset;

				if (dataPos < (SSD1306_BUFFERSIZE - SSD1306_WIDTH)) 
				{
					buffer[dataPos + SSD1306_WIDTH] |= currentByte >> (8 - yOffset);
				}
			} 
			else 
			{
				// Make new offset position
				yOffset = -yOffset;
				
				buffer[dataPos] |= currentByte >> yOffset;

				// Prepare for next iteration by moving one block up
				yMove -= 8;

				// and setting the new yOffset
				yOffset = 8 - yOffset;
			}
		}
	}
}