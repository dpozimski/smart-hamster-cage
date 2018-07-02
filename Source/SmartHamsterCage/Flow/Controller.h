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
        /************************************************************************/
        /* Updates the current state of the controller                          */
        /************************************************************************/
        virtual void update();
        /************************************************************************/
        /* Sets the elapsed seconds since program start                         */
        /************************************************************************/
        void setElapsedSeconds(uint32_t elapsedSeconds);
    protected:
        /************************************************************************/
        /* Gets the elapsed seconds since program start                         */
        /************************************************************************/
        uint32_t getElapsedSeconds();
    private:
        uint32_t elapsedSeconds = 0;
};


#endif /* CONTROLLER_H_ */