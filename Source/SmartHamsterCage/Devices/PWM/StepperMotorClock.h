/*
 * StepperMotorClock.h
 *
 * Created: 15.04.2018 15:21:32
 *  Author: d.pozimski
 */ 


#ifndef STEPPERMOTORCLOCK_H_
#define STEPPERMOTORCLOCK_H_

#include "PWMDevice.h"

class StepperMotorClock : public PWMDevice
{
    public:
        /************************************************************************/
        /* Initializes the clock of stepper motor device                        */
        /************************************************************************/
        void init() override;
    protected:
        /************************************************************************/
        /* Updates the pwm register with value                                  */
        /************************************************************************/
        void updatePwmRegister(uint8_t value) override;
};



#endif /* STEPPERMOTORCLOCK_H_ */