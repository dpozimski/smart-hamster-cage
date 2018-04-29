/*
 * OutputController.h
 *
 * Created: 29.04.2018 14:53:55
 *  Author: d.pozimski
 */ 


#ifndef OUTPUTCONTROLLER_H_
#define OUTPUTCONTROLLER_H_

#include <stdbool.h>
#include <stdio.h>

class OutputTimeRule
{
    public:
        void update(uint32_t elapsedSeconds, uint16_t onDuration, uint16_t offDuration);
        bool isOutputShouldBeEnabled();
    private:
        bool shouldBeEnabled = false;
        uint32_t outputWasActivatedTimeStamp = 0;
        uint32_t outputWasDisabledTimeStamp = 0;
};



#endif /* OUTPUTCONTROLLER_H_ */