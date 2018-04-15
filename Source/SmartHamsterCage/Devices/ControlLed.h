/*
 * ControlLed.h
 *
 * Created: 15.04.2018 20:06:16
 *  Author: d.pozimski
 */ 


#ifndef CONTROLLED_H_
#define CONTROLLED_H_

#include "Device.h"
#include <stdbool.h>

class ControlLed : public Device
{
	public:
		void init() override;
		void signal();
		bool readValue();
		void setValue(bool value);
};


#endif /* CONTROLLED_H_ */