/*
 * File:   pin_manager.c
 * Author: juand
 *
 * Created on April 14, 2020, 10:17 PM
 */

#include <xc.h>
#include "pin_manager.h"
void PIN_MANAGER_Initialize (void)
{
    //LED1_SetDigitalOutput();
    LED2_SetDigitalOutput();
    Trigger1_SetDigitalOutput();
    Trigger2_SetDigitalOutput();
    Trigger3_SetDigitalOutput();
    //LED1_SetOn();
    LED2_SetOn();
    Trigger1_SetOff();
    Trigger2_SetOff();
    Trigger3_SetOff();
    
}

