/*
 * FanController.h
 *
 * Created: 18.04.2018 21:07:03
 *  Author: d.pozimski
 */ 


#ifndef FANCONTROLLER_H_
#define FANCONTROLLER_H_

#include "./../Devices/PWM/Fan.h"
#include "Controller.h"

class FanController : public Controller
{
	public:
        /************************************************************************/
        /* Constructs a fan controller using fan device                         */
        /************************************************************************/
		FanController(Fan* fan);
        /************************************************************************/
        /* Updates the current state of the controller                          */
        /************************************************************************/
        void update() override;
        /************************************************************************/
        /* Sets the current temperature                                         */
        /************************************************************************/
        void setTemperature(uint8_t temperature);
	private:
        /************************************************************************/
        /* Calculates the pwm value using current temperature                   */
        /************************************************************************/
        uint8_t getPwmValueFromTemperature();
		Fan* fan;
        uint32_t lastExceededTimeStamp = 0;
        uint8_t temperature = 0;
};



#endif /* FANCONTROLLER_H_ */