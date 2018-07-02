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

/************************************************************************/
/* The helper class for controlling the enable/disable state            */
/* depends of the on/off parameter and the elapsed time                 */
/************************************************************************/
class OutputTimeRule
{
    public:
        /************************************************************************/
        /* Checks for the new result of the isOutputShouldBeEnabled method      */
        /************************************************************************/
        void update(uint32_t elapsedSeconds, uint16_t onDuration, uint16_t offDuration);
        /************************************************************************/
        /* Returns the indicator that the rules given from update are           */
        /* accepted to enable or disable the output                             */
        /************************************************************************/
        bool isOutputShouldBeEnabled();
    private:
        bool shouldBeEnabled = false;
        uint32_t outputWasActivatedTimeStamp = 0;
        uint32_t outputWasDisabledTimeStamp = 0;
};



#endif /* OUTPUTCONTROLLER_H_ */