/*
 * OutputController.h
 *
 * Created: 29.04.2018 14:53:55
 *  Author: dpsol
 */ 


#ifndef OUTPUTCONTROLLER_H_
#define OUTPUTCONTROLLER_H_

#include "Controller.h"
#include <stdbool.h>

class OutputTimeController : Controller
{
    public:
        OutputTimeController(uint16_t onDuration, uint16_t offDuration);
        void update() override;
        bool isOutputShouldBeEnabled();
        uint32_t getElapsedSeconds();
    private:
        bool shouldBeEnabled;
        uint16_t onDuration;
        uint16_t offDuration;
        uint32_t outputWasActivatedTimeStamp;
        uint32_t outputWasDisabledTimeStamp;
};



#endif /* OUTPUTCONTROLLER_H_ */