/*
 * FoodFeedController.cpp
 *
 * Created: 18.04.2018 21:09:38
 *  Author: d.pozimski
 */ 

#define ROTATE_PWM_VALUE 255
#define FEED_CYCLIC_DURATION 150
#define FEED_DURATION 20

#include "FoodFeedController.h"

FoodFeedController::FoodFeedController(StepperMotor* stepperMotor, OutputTimeRule* outputTimeRule)
{
    this->outputTimeRule = outputTimeRule;
    this->stepperMotor = stepperMotor;
    this->stepperMotor->setEnabled(false);
    this->stepperMotor->setSpeed(0);
    this->stepperMotor->setSpeedMode(StepperMotorSpeedMode::FULL);
    this->stepperMotor->setDirection(StepperMotorDirection::LEFT);
}

void FoodFeedController::update()
{
    uint32_t elapsedSeconds = this->getElapsedSeconds();
    this->outputTimeRule->update(elapsedSeconds, FEED_DURATION, FEED_CYCLIC_DURATION);
    
    if(this->outputTimeRule->isOutputShouldBeEnabled() && !this->stepperMotor->isEnabled())
    {
        //turn on feeder
        this->stepperMotor->setEnabled(true);
        this->stepperMotor->setSpeed(ROTATE_PWM_VALUE);
    }
    else if(!this->outputTimeRule->isOutputShouldBeEnabled() && this->stepperMotor->isEnabled())
    {
        //turn off feeder
        this->stepperMotor->setEnabled(false);
        this->stepperMotor->setSpeed(0);
    }
}
