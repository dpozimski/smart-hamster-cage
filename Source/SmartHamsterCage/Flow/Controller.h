/*
 * Controller.h
 *
 * Created: 19.04.2018 17:34:51
 *  Author: d.pozimski
 */ 

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "./../Devices/Timer.h"

class Controller
{
    public:
        virtual void update();
        void setElapsedSeconds(uint32_t elapsedSeconds);
    protected:
        uint32_t getElapsedSeconds();
    private:
        uint32_t elapsedSeconds;
};


#endif /* CONTROLLER_H_ */