/*
 * Source.cpp
 *
 * Created: 30.03.2018 15:06:01
 * Author : d.pozimski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Devices/PWM/Fan.h"
#include "Devices/PWM/WaterPump.h"
#include "Devices/ControlLed.h"
#include "Devices/I2C/Thermometer.h"
#include "Devices/I2C/OLED/OLED_Screen.h"
#include "Devices/StepperMotor.h"
#include "Flow/UIController.h"
#include "Flow/WaterFeedController.h"
#include "Flow/FanController.h"
#include "Flow/FoodFeedController.h"


int main(void)
{
    //enable interrupts
    sei();

    //Init devices
    Fan fan;
    WaterPump waterPump;
	ControlLed controlLed;
	StepperMotor stepperMotor;
	Thermometer thermometer;
	OLEDScreen oledScreen;
	fan.init();
	waterPump.init();
	controlLed.init();
	stepperMotor.init();
	oledScreen.init();
	thermometer.init();
	
	//Flow objects
	UIController uiController(&oledScreen);
	FanController fanController(&fan);
	FoodFeedController foodFeedController(&stepperMotor);
	WaterFeedController waterFeedController(&waterPump);
	
	while(true)
	{
		uiController.display();
	}
}

