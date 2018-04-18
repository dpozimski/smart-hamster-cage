/*
 * FanController.h
 *
 * Created: 18.04.2018 21:07:03
 *  Author: d.pozimski
 */ 


#ifndef FANCONTROLLER_H_
#define FANCONTROLLER_H_

#include "./../Devices/PWM/Fan.h"

class FanController
{
	public:
		FanController(Fan* fan);
	private:
		Fan* fan;
};



#endif /* FANCONTROLLER_H_ */