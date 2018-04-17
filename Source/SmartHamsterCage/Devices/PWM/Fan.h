/*
 * Fan.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: d.pozimski
 */ 


#ifndef FAN_H_
#define FAN_H_

#include "PWMDevice.h"

class Fan : public PWMDevice
{
    public:
        void init() override;
    protected:
        void updatePwmRegister() override;
};


#endif /* FAN_H_ */