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
		WaterFeedController(WaterPump* waterPump);
        void update() override;
        void setTemperature(uint8_t temperature);
	private:
        uint8_t getDurationOfWaterPouring(uint32_t elapsedSeconds);
        uint8_t temperature;
        uint32_t lastExceededTimeStamp;
		WaterPump* waterPump;
};


#endif /* WATERFEEDCONTROLLER_H_ */