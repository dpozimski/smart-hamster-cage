/*
 * WaterPump.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: dpsol
 */ 


#ifndef WaterPump_H_
#define WaterPump_H_

#include "PWMDevice.h"

class WaterPump : PWMDevice
{
    public:
        void init() override;
    protected:
        void updatePwmRegister() override;
};


#endif /* WaterPump_H_ */