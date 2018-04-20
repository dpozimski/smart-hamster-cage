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
		FanController(Fan* fan, Timer* timer);
        void update() override;
	private:
		Fan* fan;
};



#endif /* FANCONTROLLER_H_ */