/*
 * UIController.h
 *
 * Created: 18.04.2018 20:44:00
 *  Author: d.pozimski
 */ 


#ifndef UICONTROLLER_H_
#define UICONTROLLER_H_

#define TEXT_BUFFER_SIZE 512

#include "Controller.h"
#include "../Devices/I2C/OLED/OLED_Screen.h"
#include <stdbool.h>

class UIController : public Controller
{
	public:
		UIController(OLEDScreen* view);
		void setTemperature(uint8_t value);
		void isFanWorking(bool value);
		void isWaterPumpWorking(bool value);
		void isControlLedActive(bool value);
		void isStepperMotorWorking(bool value);
		void update() override;
	private:
		OLEDScreen* view;
		uint8_t temperature = 0;
		bool fanWorking = false;
		bool controlLedActive = false;
		bool stepperMotorWorking = false;
		bool waterPumpWorking = false;
        char buffer[TEXT_BUFFER_SIZE];
};


#endif /* UICONTROLLER_H_ */