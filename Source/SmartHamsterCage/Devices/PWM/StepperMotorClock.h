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
        void init() override;
    protected:
        void updatePwmRegister(uint8_t value) override;
};



#endif /* STEPPERMOTORCLOCK_H_ */