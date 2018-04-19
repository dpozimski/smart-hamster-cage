/*
 * FanController.h
 *
 * Created: 18.04.2018 21:07:03
 *  Author: d.pozimski
 */ 


#ifndef FANCONTROLLER_H_
#define FANCONTROLLER_H_

#include "Controller.h"
#include "./../Devices/PWM/Fan.h"

class FanController : public Controller
{
	public:
		FanController(Fan* fan);
        void update() override;
	private:
		Fan* fan;
};



#endif /* FANCONTROLLER_H_ */