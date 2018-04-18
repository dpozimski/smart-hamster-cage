/*
 * FoodFeedController.h
 *
 * Created: 18.04.2018 21:09:02
 *  Author: d.pozimski
 */ 


#ifndef FOODFEEDCONTROLLER_H_
#define FOODFEEDCONTROLLER_H_

#include "../Devices/StepperMotor.h"

class FoodFeedController
{
	public:
		FoodFeedController(StepperMotor* stepperMotor);
	private:
		StepperMotor* stepperMotor;	
};



#endif /* FOODFEEDCONTROLLER_H_ */