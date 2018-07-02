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
        /************************************************************************/
        /* Constructs a water feed controller using water pump device           */
        /* and the output time rule handler                                     */
        /************************************************************************/
		WaterFeedController(WaterPump* waterPump, OutputTimeRule* outputTimeRule);
        /************************************************************************/
        /* Updates the current state of the controller                          */
        /************************************************************************/
        void update() override;
        /************************************************************************/
        /* Sets the current temperature                                         */
        /************************************************************************/
        void setTemperature(uint8_t temperature);
	private:
        /************************************************************************/
        /* Get the idle time of the device depends of temperature               */
        /************************************************************************/
        uint8_t getIdleTime(uint32_t elapsedSeconds);
        uint8_t temperature = 0;
		WaterPump* waterPump;
        OutputTimeRule* outputTimeRule;
};


#endif /* WATERFEEDCONTROLLER_H_ */