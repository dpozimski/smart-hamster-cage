/*
 * UIController.cpp
 *
 * Created: 18.04.2018 20:48:22
 *  Author: d.pozimski
 */ 

#include "UIController.h"

#include <string.h>
#include <stdio.h>

UIController::UIController(OLEDScreen* view) : view(view)
{
	
}

void UIController::setTemperature(uint8_t value)
{
	this->temperature = value;
}

void UIController::isFanWorking(bool value)
{
	this->fanWorking = value;
}

void UIController::isWaterPumpWorking(bool value)
{
	this->waterPumpWorking = value;
}

void UIController::isControlLedActive(bool value)
{
	this->controlLedActive = value;
}

void UIController::isStepperMotorWorking(bool value)
{
	this->stepperMotorWorking = value;
}

void UIController::update()
{
    //clear buffer in screen
	this->view->clearBuffer();
    //clear buffers
    memset(this->buffer, 0, TEXT_BUFFER_SIZE);
    //place formatted text into the ready to go buffer
    sprintf(this->buffer, 
        "Current temperature: %d\nFan: %d\nWater pump: %d\nControl led: %d\nStepper motor: %d\n",
        this->temperature, this->fanWorking, this->waterPumpWorking, this->controlLedActive, this->stepperMotorWorking);
    //draw text
	this->view->drawText(0, 0, this->buffer);
	this->view->flush();
}
