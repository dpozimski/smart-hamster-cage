/*
 * UIController.cpp
 *
 * Created: 18.04.2018 20:48:22
 *  Author: d.pozimski
 */ 

#include "UIController.h"

#include <string.h>
#include <stdio.h>

UIController::UIController(OLEDScreen* view)
{
	this->view = view;
}

void UIController::setTemperature(uint8_t value)
{
	this->temperature = value;
}

void UIController::setFanSpeed(uint8_t value)
{
	this->fanSpeed = value;
}

void UIController::setWaterPumpPower(uint8_t value)
{
	this->waterPumpPower = value;
}

void UIController::setStepperMotorSpeed(uint8_t value)
{
	this->stepperMotorSpeed = value;
}

void UIController::update()
{
    //clear buffers
	this->view->clearBuffer(); 
    memset(this->buffer, 0, TEXT_BUFFER_SIZE);
    //title
    const char* titleText = "SMART Hamster Cage";
    this->view->drawTitle(titleText);
    //place formatted text into the ready to go buffer
    sprintf(this->buffer, 
        "Temperature: %dC\nFan: %d%%\nWater pump: %d%%\nStepper motor: %d%%\nElapsed time: %lus\n",
        this->temperature, 
        this->pwmToPercentValue(this->fanSpeed), 
        this->pwmToPercentValue(this->waterPumpPower), 
        this->pwmToPercentValue(this->stepperMotorSpeed),
        this->getElapsedSeconds());
    //draw text
	this->view->drawText(0, 0, this->buffer);
	this->view->flush();
}

uint8_t UIController::pwmToPercentValue(uint8_t pwmValue)
{
    return (pwmValue * 100) / 255;
}
