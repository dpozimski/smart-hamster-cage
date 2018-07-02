/*
 * Device.h
 *
 * Created: 15.04.2018 17:08:41
 *  Author: d.pozimski
 */ 


#ifndef DEVICE_H_
#define DEVICE_H_

class Device
{
    public:
        /************************************************************************/
        /* Should be used to initialize a device                                */
        /************************************************************************/
        virtual void init() = 0;
};


#endif /* DEVICE_H_ */