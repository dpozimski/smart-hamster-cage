/*
 * FoodFeedController.h
 *
 * Created: 18.04.2018 21:09:02
 *  Author: d.pozimski
 */ 


#ifndef FOODFEEDCONTROLLER_H_
#define FOODFEEDCONTROLLER_H_

#include "Controller.h"
#include "../Devices/StepperMotor.h"
#include <stdbool.h>

class FoodFeedController : public Controller
{
	public:
		FoodFeedController(StepperMotor* stepperMotor, Timer* timer);
        void update() override;
	private:
		StepperMotor* stepperMotor;	
        uint32_t lastExceededTimeStamp;
};



#endif /* FOODFEEDCONTROLLER_H_ */