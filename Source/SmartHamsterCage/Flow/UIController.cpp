/*
 * UIController.cpp
 *
 * Created: 18.04.2018 20:48:22
 *  Author: d.pozimski
 */ 

#include "UIController.h"

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

void UIController::display()
{
	this->view->clearBuffer();
	this->view->drawText(0, 0, (char*)"bla bla");
	this->view->flush();
}
