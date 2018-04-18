/*
 * UIController.h
 *
 * Created: 18.04.2018 20:44:00
 *  Author: d.pozimski
 */ 


#ifndef UICONTROLLER_H_
#define UICONTROLLER_H_

#include "../Devices/I2C/OLED/OLED_Screen.h"
#include <stdbool.h>

class UIController
{
	public:
		UIController(OLEDScreen* view);
		void setTemperature(uint8_t value);
		void isFanWorking(bool value);
		void isWaterPumpWorking(bool value);
		void isControlLedActive(bool value);
		void isStepperMotorWorking(bool value);
		void display();
	private:
		OLEDScreen* view;
		uint8_t temperature;
		bool fanWorking;
		bool controlLedActive;
		bool stepperMotorWorking;
		bool waterPumpWorking;
};


#endif /* UICONTROLLER_H_ */