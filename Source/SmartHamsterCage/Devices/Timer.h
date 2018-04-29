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
        void init() override;
        uint32_t getElapsedSeconds();  
        static void incrementElapsedSeconds();
    private:
        static uint32_t elapsedSeconds;
};



#endif /* TIMER_H_ */