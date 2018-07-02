/*
 * Timer.h
 *
 * Created: 19.04.2018 18:16:18
 *  Author: d.pozimski
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "Device.h"
#include <stdint.h>

class Timer: public Device
{
    public:
        /************************************************************************/
        /* Initializes timer by setting the TIMER0 into the PWM inverted mode   */
        /************************************************************************/
        void init() override;
        /************************************************************************/
        /* Gets elapsed seconds since program start                             */
        /************************************************************************/
        uint32_t getElapsedSeconds();  
        /************************************************************************/
        /* It should be used only to increase elapsedSeconds                    */
        /* variable directly from TIMER vector                                  */                                     
        /************************************************************************/
        static void incrementElapsedSeconds();
    private:
        static uint32_t elapsedSeconds;
};



#endif /* TIMER_H_ */