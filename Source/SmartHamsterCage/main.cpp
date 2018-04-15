/*
 * Source.cpp
 *
 * Created: 30.03.2018 15:06:01
 * Author : d.pozimski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Devices/I2C/I2CDevice.h"
#include "Devices/PWM/Fan.h"
#include "Devices/PWM/WaterPump.h"
#include "Devices/ControlLed.h"
#include "Devices/I2C/OLED/SSD1306_Adapter.h"


int main(void)
{
    //enable interrupts
    sei();

    //Init devices
    Fan fan;
    WaterPump waterPump;
	ControlLed controlLed;
	SSD1306Adapter ssd1306;
	
    fan.init();
    waterPump.init();
	controlLed.init();
	ssd1306.init();
}

