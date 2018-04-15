/*
 * StepperMotor.cpp
 *
 * Created: 15.04.2018 17:43:38
 *  Author: dpsol
 */ 

#include "StepperMotor.h"
#include "./../PinConfiguration.h"
#include <avr/io.h>

void StepperMotor::init()
{
    PORTA = (1 << SP_DIR) | (1 << SP_HALF_FULL_MODE) | (1 << SP_ENABLE);
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
