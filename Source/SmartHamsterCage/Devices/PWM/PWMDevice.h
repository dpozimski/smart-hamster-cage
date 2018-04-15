/*
 * PWMDevice.h
 *
 * Created: 15.04.2018 13:42:46
 *  Author: dpsol
 */ 


#ifndef PWMDEVICE_H_
#define PWMDEVICE_H_

#include <stdint.h>
#include "./../Device.h"

class PWMDevice : public Device
{
    public:
        void setValue(uint8_t value);
        uint8_t readValue();
    protected:
        virtual void updatePwmRegister() = 0;
        uint8_t value;
};

#endif /* PWMDEVICE_H_ */