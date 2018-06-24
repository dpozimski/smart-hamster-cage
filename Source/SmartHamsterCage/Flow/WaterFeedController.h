/*
 * WaterFeedController.h
 *
 * Created: 18.04.2018 21:11:02
 *  Author: d.pozimski
 */ 


#ifndef WATERFEEDCONTROLLER_H_
#define WATERFEEDCONTROLLER_H_

#include "Controller.h"
#include "./../Utils/OutputTimeRule.h"
#include "./../Devices/PWM/WaterPump.h"

class WaterFeedController : public Controller
{
	public:
		WaterFeedController(WaterPump* waterPump, OutputTimeRule* outputTimeRule);
        void update() override;
        void setTemperature(uint8_t temperature);
	private:
        uint8_t getIdleTime(uint32_t elapsedSeconds);
        uint8_t temperature = 0;
		WaterPump* waterPump;
        OutputTimeRule* outputTimeRule;
};


#endif /* WATERFEEDCONTROLLER_H_ */