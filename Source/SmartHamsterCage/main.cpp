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
#include "Devices/Timer.h"
#include "Flow/UIController.h"
#include "Flow/WaterFeedController.h"
#include "Flow/FanController.h"
#include "Flow/FoodFeedController.h"

uint8_t getPwmValueFromTemperature(uint8_t vale)
{
    int16_t y2 = 255, y1 = 50;
    int16_t x2 = 30, x1 = 26;
    //linear function
    uint8_t y = ( ((y2 - y1)/(x2 - x1)) * vale ) + ( ((x2 * y1) - (x1 * y2)) / (x2 - x1) );
    return y;
}

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
	//OLEDScreen oledScreen;
    Timer timer;
    timer.init();
	fan.init();
	waterPump.init();
	controlLed.init();
	stepperMotor.init();
	//oledScreen.init();
	thermometer.init();
    
    //Rule objects
    OutputTimeRule waterFeedTimeRule;
    OutputTimeRule foodFeedTimeRule;
	
	//Flow objects
	//UIController uiController(&oledScreen);
	FanController fanController(&fan);
	FoodFeedController foodFeedController(&stepperMotor, &foodFeedTimeRule);
	WaterFeedController waterFeedController(&waterPump, &waterFeedTimeRule);
    
	while(true)
	{  
        
        //get temperature measure
    	uint8_t temperature = thermometer.getTemperature();
        uint32_t elapsedSeconds = timer.getElapsedSeconds();
        
        //set updated values
        fanController.setTemperature(temperature);
        waterFeedController.setTemperature(temperature);
        //uiController.setTemperature(temperature);
        fanController.setElapsedSeconds(elapsedSeconds);
        waterFeedController.setElapsedSeconds(elapsedSeconds);
        foodFeedController.setElapsedSeconds(elapsedSeconds);
        //uiController.setElapsedSeconds(elapsedSeconds);
        
        //output devices work
        fanController.update();
        waterFeedController.update();
        foodFeedController.update();
        
        //ui
        //uiController.isControlLedActive(controlLed.readValue());
        //uiController.isFanWorking(fan.readValue());
        //uiController.isStepperMotorWorking(stepperMotor.readSpeed());
        //uiController.isWaterPumpWorking(waterPump.readValue());
        //uiController.update();
	}
}

