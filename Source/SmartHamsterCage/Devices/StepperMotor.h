/*
 * StepperMotor.h
 *
 * Created: 15.04.2018 17:18:07
 *  Author: dpsol
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_

#include "Device.h"
#include "./PWM/StepperMotorClock.h"
#include <stdbool.h>

enum StepperMotorDirection
{
    LEFT = 0,
    RIGHT = 1
};

enum StepperMotorSpeedMode
{
    HALF = 0,
    FULL = 1
};

class StepperMotor : Device
{
    public:
        void init() override;
        void setDirection(StepperMotorDirection direction);
        StepperMotorDirection readDirection();
        void setSpeed(uint8_t value);
        uint8_t readSpeed();
        void setSpeedMode(StepperMotorSpeedMode speedMode);
        StepperMotorSpeedMode readSpeedMode();        
    private:
        bool isEnabled();
        void setEnabled(bool value);
        StepperMotorClock stepperMotorClock;
};


#endif /* STEPPERMOTOR_H_ */