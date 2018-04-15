/*
 * Source.cpp
 *
 * Created: 30.03.2018 15:06:01
 * Author : d.pozimski
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

#include "Devices/I2C/I2CDevice.h"
#include "Devices/PWM/Fan.h"
#include "Devices/PWM/WaterPump.h"


int main(void)
{
    //enable interrupts
    sei();
    //Init i2c bus
    I2CDevice::initBus();

    //Init pwm devices
    Fan fan;
    WaterPump waterPump;
    fan.init();
    waterPump.init();
}

