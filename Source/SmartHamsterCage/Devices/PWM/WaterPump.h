/*
 * WaterPump.h
 *
 * Created: 15.04.2018 13:28:33
 *  Author: d.pozimski
 */ 


#ifndef WaterPump_H_
#define WaterPump_H_

#include "PWMDevice.h"

class WaterPump : public PWMDevice
{
    public:
        /************************************************************************/
        /* Initializes the clock of stepper motor device                        */
        /************************************************************************/
        void init() override;
    protected:
        /************************************************************************/
        /* Updates the pwm register with value                                  */
        /************************************************************************/
        void updatePwmRegister(uint8_t value) override;
};


#endif /* WaterPump_H_ */