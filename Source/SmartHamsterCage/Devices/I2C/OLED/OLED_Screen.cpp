/*
 * OLEDScreen.cpp
 *
 * Created: 15.04.2018 21:28:17
 *  Author: d.pozimski
 */ 

#include "OLED_Screen.h"
#include "OLED_Fonts.h"

void OLEDScreen::init()
{
	this->ssd1306.init();
}