/*
 * File:   interrupts.c
 * Author: juand
 *
 * Created on April 14, 2020, 10:24 PM
 */


#include <xc.h>
#include "interrupts.h"

void INTERRUPT_Initialize(void)
{
     
    GIEH = 1; // Enable interruption priority
    IPEN = 1; // Enable High priority interruptions
    TMR0IE = 1; //Enable TRMR0 interrupt
    TMR0IP = 1; //TMR0 interrupt as Low Priority
    INT0IE = 1;// INT0 External Interrupt Enable bit 
    INTEDG0 = 0;// External Interrupt0 Edge Select bit
    CCP1IP = 1; //CCP1 Interrupt Priority bit
    CCP1IE = 1; //CCP1 Interrupt Enable bit
    CCP2IP = 1; //CCP2 Interrupt Priority bit
    CCP2IE = 1; //CCP2 Interrupt Enable bit
    //SSPIE = 1; //I2C Interrupt enable
    //SSPIP = 1; //I2C High prirority interruption
}

