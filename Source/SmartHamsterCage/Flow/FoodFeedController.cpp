/*
 * FoodFeedController.cpp
 *
 * Created: 18.04.2018 21:09:38
 *  Author: d.pozimski
 */ 

#include "FoodFeedController.h"

FoodFeedController::FoodFeedController(StepperMotor* stepperMotor, Timer* timer) : Controller::Controller(timer)
{
    this->stepperMotor = stepperMotor;
}

void FoodFeedController::update()
{

}
