/*
 * UIController.h
 *
 * Created: 18.04.2018 20:44:00
 *  Author: d.pozimski
 */ 


#ifndef UICONTROLLER_H_
#define UICONTROLLER_H_

#define TEXT_BUFFER_SIZE 256

#include "Controller.h"
#include "../Devices/I2C/OLED/OLED_Screen.h"
#include <stdbool.h>

class UIController : public Controller
{
	public:
		UIController(OLEDScreen* view);
        /************************************************************************/
        /* Sets the current temperature                                         */
        /************************************************************************/
		void setTemperature(uint8_t value);
		void setFanSpeed(uint8_t value);
		void setWaterPumpPower(uint8_t value);
		void setStepperMotorSpeed(uint8_t value);
        /************************************************************************/
        /* Updates the current state of the controller                          */
        /************************************************************************/
		void update() override;
	private:
        uint8_t pwmToPercentValue(uint8_t pwmValue);
		OLEDScreen* view;
		uint8_t temperature = 0;
		uint8_t fanSpeed = false;
		uint8_t stepperMotorSpeed = false;
		uint8_t waterPumpPower = false;
        char buffer[TEXT_BUFFER_SIZE];
};


#endif /* UICONTROLLER_H_ */