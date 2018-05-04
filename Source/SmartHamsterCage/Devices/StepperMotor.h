/*
 * StepperMotor.h
 *
 * Created: 15.04.2018 17:18:07
 *  Author: d.pozimski
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
        void setSpeed(uint16_t value);
        uint16_t readSpeed();
        void setSpeedMode(StepperMotorSpeedMode speedMode);
        StepperMotorSpeedMode readSpeedMode();   
        bool isEnabled();
        void setEnabled(bool value);     
    private:
        StepperMotorClock stepperMotorClock;
};


#endif /* STEPPERMOTOR_H_ */