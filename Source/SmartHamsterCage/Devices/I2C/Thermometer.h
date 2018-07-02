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
        /************************************************************************/
        /* Creates a new instance of the thermometer device                     */
        /************************************************************************/
        Thermometer();
        /************************************************************************/
        /* Initializes DS1621 module connected to I2C bus                       */
        /************************************************************************/
        void init() override;
        /************************************************************************/
        /* Gets current temperature from the device                             */
        /************************************************************************/
		float getTemperature();
};

#endif /* THERMOMETER_H_ */