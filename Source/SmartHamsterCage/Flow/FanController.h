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
		FanController(Fan* fan);
        void update() override;
        void setTemperature(uint8_t temperature);
	private:
        uint8_t getPwmValueFromTemperature();
		Fan* fan;
        uint32_t lastExceededTimeStamp = 0;
        uint8_t temperature = 0;
};



#endif /* FANCONTROLLER_H_ */