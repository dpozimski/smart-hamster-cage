/*
 * StepperMotor.cpp
 *
 * Created: 15.04.2018 17:43:38
 *  Author: d.pozimski
 */ 

#define SP_ENABLE PA1
#define SP_DIR PA0
#define SP_HALF_FULL_MODE PA2

#include "StepperMotor.h"
#include "./../Utils/Bits.h"
#include <avr/io.h>

void StepperMotor::init()
{
	this->stepperMotorClock.init();
    DDRA |= (1 << SP_DIR) | (1 << SP_HALF_FULL_MODE) | (1 << SP_ENABLE);
	this->setDirection(StepperMotorDirection::RIGHT);
	this->setSpeedMode(StepperMotorSpeedMode::HALF);
	this->setEnabled(false);
}

void StepperMotor::setDirection(StepperMotorDirection direction)
{
    Bits::setPortValue(&PORTA, SP_DIR, direction);
}

StepperMotorDirection StepperMotor::readDirection()
{
    return static_cast<StepperMotorDirection>(Bits::readPinValue(&PINA, SP_DIR));
}

void StepperMotor::setSpeed(uint16_t value)
{
    this->stepperMotorClock.setValue(value);
}

uint16_t StepperMotor::readSpeed()
{
    return this->stepperMotorClock.readValue();
}

void StepperMotor::setSpeedMode(StepperMotorSpeedMode speedMode)
{
    Bits::setPortValue(&PORTA, SP_HALF_FULL_MODE, speedMode);
}

StepperMotorSpeedMode StepperMotor::readSpeedMode()
{
    return static_cast<StepperMotorSpeedMode>(Bits::readPinValue(&PINA, SP_HALF_FULL_MODE));
}

void StepperMotor::setEnabled(bool value)
{
    Bits::setPortValue(&PORTA, SP_ENABLE, value);
}

bool StepperMotor::isEnabled()
{
    return Bits::readPinValue(&PINA, SP_ENABLE);
}
