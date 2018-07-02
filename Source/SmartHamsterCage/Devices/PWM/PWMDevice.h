/*
 * PWMDevice.h
 *
 * Created: 15.04.2018 13:42:46
 *  Author: d.pozimski
 */ 


#ifndef PWMDEVICE_H_
#define PWMDEVICE_H_

#include <stdint.h>
#include "./../Device.h"

class PWMDevice : public Device
{
    public:
        /************************************************************************/
        /* Sets the PWM value                                                   */
        /************************************************************************/
        void setValue(uint8_t value);
        /************************************************************************/
        /* Reads the current PWM value                                          */
        /************************************************************************/
        uint8_t readValue();
    protected:
        /************************************************************************/
        /* It should be used to sets the PWM value directly to OCRx register    */
        /************************************************************************/
        virtual void updatePwmRegister(uint8_t value) = 0;
    private:
        /************************************************************************/
        /* Reverse user pwm value to handle inverted PWM configuration          */
        /************************************************************************/
        uint8_t reverseValue(uint8_t value);
        uint8_t value = 0;
};

#endif /* PWMDEVICE_H_ */