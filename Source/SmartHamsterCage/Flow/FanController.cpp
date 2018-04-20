/*
 * FanController.cpp
 *
 * Created: 18.04.2018 21:07:12
 *  Author: d.pozimski
 */ 

#include "FanController.h"

FanController::FanController(Fan* fan, Timer* timer) : Controller::Controller(timer)
{
    this->fan = fan;
}

void FanController::update()
{

}
