/*
 * Fan.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: d.pozimski
 */ 


#ifndef FAN_H_
#define FAN_H_

#include "PWMDevice.h"

class Fan : public PWMDevice
{
    public:
        /************************************************************************/
        /* Initializes fan control by setting the timer 1b to inverted pwm mode */
        /************************************************************************/
        void init() override;
    protected:
        /************************************************************************/
        /* Sets the PWM value of the timer - physically it sets the speed       */
        /************************************************************************/
        void updatePwmRegister(uint8_t value) override;
};


#endif /* FAN_H_ */