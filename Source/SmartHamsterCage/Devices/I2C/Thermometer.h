/*
 * Thermometer.h
 *
 * Created: 17.04.2018 18:25:15
 *  Author: d.pozimski
 */ 


#ifndef THERMOMETER_H_
#define THERMOMETER_H_

#include "I2CDevice.h"

class Thermometer : public I2CDevice
{
    public:
        Thermometer();
        void init() override;
		float getTemperature();
};

#endif /* THERMOMETER_H_ */