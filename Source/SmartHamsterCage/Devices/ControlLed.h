/*
 * ControlLed.h
 *
 * Created: 15.04.2018 20:06:16
 *  Author: d.pozimski
 */ 


#ifndef CONTROLLED_H_
#define CONTROLLED_H_

#include "Device.h"
#include <stdbool.h>

class ControlLed : public Device
{
	public:
        /************************************************************************/
        /* Initialize the control led device                                    */
        /************************************************************************/
		void init() override;
        /************************************************************************/
        /* Execute a signal procedure with toggling LED diode for 50ms          */
        /************************************************************************/
		void signal();
        /************************************************************************/
        /* Reads the current state of the diode                                 */
        /************************************************************************/
		bool readValue();
        /************************************************************************/
        /* Sets the new state of the diode                                      */
        /************************************************************************/
		void setValue(bool value);
};


#endif /* CONTROLLED_H_ */