/*
 * File:   system.c
 * Author: juand
 *
 * Created on April 14, 2020, 10:21 PM
 */


#include <xc.h>
#include "system.h"
#include "pin_manager.h"
#include "interrupts.h"
#include "timer0.h"
//#include "I2C_SLAVE.h"

void SYSTEM_Initialize(void)
{
    OSCCON = 0b01110000;
    PIN_MANAGER_Initialize();
    TMR0_Initialize();
    INTERRUPT_Initialize();
    CCP1CON = 0b00000100;
    CCP2CON = 0b00000100;
    
}
