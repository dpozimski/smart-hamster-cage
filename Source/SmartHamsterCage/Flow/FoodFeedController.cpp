/*
 * FoodFeedController.cpp
 *
 * Created: 18.04.2018 21:09:38
 *  Author: d.pozimski
 */ 

#define ROTATE_PWM_VALUE 100
#define FEED_CYCLIC_DURATION 150
#define FEED_DURATION 3

#include "FoodFeedController.h"

FoodFeedController::FoodFeedController(StepperMotor* stepperMotor, Timer* timer) : Controller::Controller(timer)
{
    this->stepperMotor = stepperMotor;
    this->stepperMotor->setEnabled(false);
    this->stepperMotor->setSpeed(ROTATE_PWM_VALUE);
    this->stepperMotor->setSpeedMode(StepperMotorSpeedMode::HALF);
    this->stepperMotor->setDirection(StepperMotorDirection::RIGHT);
}

void FoodFeedController::update()
{
    uint32_t elapsedSeconds = this->getTimer()->getElapsedSeconds();
    if(!(elapsedSeconds % FEED_CYCLIC_DURATION) && !this->stepperMotor->isEnabled())
    {
        //turn on feeder
        this->stepperMotor->setEnabled(true);
        this->lastExceededTimeStamp = elapsedSeconds;
    }
    else if(((elapsedSeconds - this->lastExceededTimeStamp) >= FEED_DURATION) && this->stepperMotor->isEnabled())
    {
        //turn off feeder
        this->stepperMotor->setSpeed(false);
    }
}
