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
        Controller(Timer* timer);
        virtual void update() = 0;
    protected:
        Timer* getTimer();
    private:
        Timer* timer;
};


#endif /* CONTROLLER_H_ */