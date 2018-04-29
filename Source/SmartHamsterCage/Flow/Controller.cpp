/*
 * Controller.cpp
 *
 * Created: 19.04.2018 17:34:09
 *  Author: d.pozimski
 */ 

#include "Controller.h"

void Controller::update()
{
    //blank
}

void Controller::setElapsedSeconds(uint32_t elapsedSeconds)
{
    this->elapsedSeconds = elapsedSeconds;
}

uint32_t Controller::getElapsedSeconds()
{
    return this->elapsedSeconds;
}
