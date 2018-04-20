/*
 * WaterFeedController.h
 *
 * Created: 18.04.2018 21:11:02
 *  Author: d.pozimski
 */ 


#ifndef WATERFEEDCONTROLLER_H_
#define WATERFEEDCONTROLLER_H_

#include "Controller.h"
#include "./../Devices/PWM/WaterPump.h"

class WaterFeedController : public Controller
{
	public:
		WaterFeedController(WaterPump* waterPump, Timer* timer);
        void update() override;
	private:
		WaterPump* waterPump;
};


#endif /* WATERFEEDCONTROLLER_H_ */