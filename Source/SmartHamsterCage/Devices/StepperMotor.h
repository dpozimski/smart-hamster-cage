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
        /************************************************************************/
        /* Initializes the stepper motor device                                 */
        /************************************************************************/
        void init() override;
        /************************************************************************/
        /* Sets a direction                                                     */
        /************************************************************************/
        void setDirection(StepperMotorDirection direction);
        /************************************************************************/
        /* Reads current direction                                              */
        /************************************************************************/
        StepperMotorDirection readDirection();
        /************************************************************************/
        /* Set the speed of device                                                */
        /************************************************************************/
        void setSpeed(uint16_t value);
        /************************************************************************/
        /* Reads current speed                                                  */
        /************************************************************************/
        uint16_t readSpeed();
        /************************************************************************/
        /* Sets the speed mode                                                  */
        /************************************************************************/
        void setSpeedMode(StepperMotorSpeedMode speedMode);
        /************************************************************************/
        /* Reads the speed mode                                                 */
        /************************************************************************/
        StepperMotorSpeedMode readSpeedMode();   
        /************************************************************************/
        /* Checks if the device is enabled                                      */
        /************************************************************************/
        bool isEnabled();
        /************************************************************************/
        /* Enable or disable motor speed by the additional command              */
        /************************************************************************/
        void setEnabled(bool value);     
    private:
        StepperMotorClock stepperMotorClock;
};


#endif /* STEPPERMOTOR_H_ */