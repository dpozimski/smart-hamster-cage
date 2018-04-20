/*
 * WaterFeedController.cpp
 *
 * Created: 18.04.2018 21:10:51
 *  Author: d.pozimski
 */ 

#include "WaterFeedController.h"

WaterFeedController::WaterFeedController(WaterPump* waterPump, Timer* timer) : Controller::Controller(timer)
{
    this->waterPump = waterPump;
}

void WaterFeedController::update()
{

}
