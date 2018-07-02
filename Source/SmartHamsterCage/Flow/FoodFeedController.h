/*
 * FoodFeedController.h
 *
 * Created: 18.04.2018 21:09:02
 *  Author: d.pozimski
 */ 


#ifndef FOODFEEDCONTROLLER_H_
#define FOODFEEDCONTROLLER_H_

#include "Controller.h"
#include "./../Utils/OutputTimeRule.h"
#include "../Devices/StepperMotor.h"
#include <stdbool.h>

class FoodFeedController : public Controller
{
	public:
        /************************************************************************/
        /* Constructs a food feed controller using stepper motor                */
        /* device and the output time rule handler                              */
        /************************************************************************/
		FoodFeedController(StepperMotor* stepperMotor, OutputTimeRule* outputTimeRule);
        /************************************************************************/
        /* Updates the current state of the controller                          */
        /************************************************************************/
        void update() override;
	private:
		StepperMotor* stepperMotor;
        OutputTimeRule* outputTimeRule;
};



#endif /* FOODFEEDCONTROLLER_H_ */