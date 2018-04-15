/*
 * StepperMotor.cpp
 *
 * Created: 15.04.2018 17:43:38
 *  Author: dpsol
 */ 

#define SP_ENABLE PA1
#define SP_DIR PA0
#define SP_HALF_FULL_MODE PA2

#include "StepperMotor.h"
#include <avr/io.h>

void StepperMotor::init()
{
	this->stepperMotorClock.init();
    DDRA = (1 << SP_DIR) | (1 << SP_HALF_FULL_MODE) | (1 << SP_ENABLE);
}

void StepperMotor::setDirection(StepperMotorDirection direction)
{
    PORTA &= ~(direction << SP_DIR);
}

StepperMotorDirection StepperMotor::readDirection()
{
    return static_cast<StepperMotorDirection>(bit_is_set(PINA, SP_DIR));
}

void StepperMotor::setSpeed(uint8_t value)
{
    this->stepperMotorClock.setValue(value);
}

uint8_t StepperMotor::readSpeed()
{
    return this->stepperMotorClock.readValue();
}

void StepperMotor::setSpeedMode(StepperMotorSpeedMode speedMode)
{
    PORTA &= ~(speedMode << SP_HALF_FULL_MODE);
}

StepperMotorSpeedMode StepperMotor::readSpeedMode()
{
    return static_cast<StepperMotorSpeedMode>(bit_is_set(PINA, SP_HALF_FULL_MODE));
}

void StepperMotor::setEnabled(bool value)
{
    PORTA &= ~(value << SP_ENABLE);
}

bool StepperMotor::isEnabled()
{
    return bit_is_set(PINA, SP_ENABLE);
}
