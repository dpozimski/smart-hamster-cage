/*
 * Controller.cpp
 *
 * Created: 19.04.2018 17:34:09
 *  Author: d.pozimski
 */ 

#include "Controller.h"

Controller::Controller(Timer* timer)
{
    this->timer = timer;
}

void Controller::update()
{
    //blank
}

Timer* Controller::getTimer()
{
    return this->timer;
}
