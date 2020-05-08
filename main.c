/*
 * File:   main.c
 * Author: juand
 *
 * Created on April 13, 2020, 10:59 PM
 */


#include <xc.h>
#include <pic18f2331.h>

#include "system.h"
#include "pin_manager.h"
#include "timer0.h"
#include "I2CCom.h"


//#pragma config MCLRE = OFF            // Master Clear Enable (MCLR Disabled, RG5 Enabled)
#pragma config OSC = IRCIO      // Oscillator Selection bits (Internal oscillator block, port function on RA6 and port function on RA7)
#define _XTAL_FREQ  8000000

#define USING_RIGHT_MOTOR true
#define PIC1_ADDR 0x1E
#define PIC2_ADDR 0x1F

#define INPUT_BYTES 0
#define OUTPUT_BYTES 6
#define BUF_LEN (INPUT_BYTES < OUTPUT_BYTES) ? OUTPUT_BYTES : INPUT_BYTES

#define PIC_ADDR USING_RIGHT_MOTOR ? PIC1_ADDR : PIC2_ADDR

unsigned char buffer[BUF_LEN] = {0};

unsigned int dist_1_mm = 0;
unsigned int dist_2_mm = 0;
unsigned int dist_3_mm = 0;
unsigned int test1 = 0;
unsigned int test2 = 0;

void __interrupt(high_priority) high(void)
{
    if(SSPIE && SSPIF){
        unsigned char data_state = I2CDataTransfered(buffer,INPUT_BYTES, OUTPUT_BYTES);
        
        switch(data_state){
            case RECEIVED:   
                break;
            case SENT:
                break;
            default:
                break;
        }
    }
    if(TMR0IE == 1 && TMR0IF == 1)
    {
        TMR0IF=0;  // Turn Off TMR0 interrupt flag
        TMR0_Set_Buffer();
        //LED1_Toggle();
        Trigger1_SetOn();
        Trigger2_SetOn();
        Trigger3_SetOn();
        __delay_us(10); 
        Trigger1_SetOff();
        Trigger2_SetOff();
        Trigger3_SetOff();
    }
    if(INT0IE == 1 && INT0IF == 1)
    {
       INT0IF = 0;
       //LED1_Toggle();
       dist_1_mm = (((TMR0 - 15781)*10)/29);
       buffer[0] = dist_1_mm & 0x00FF;
       buffer[1] = (dist_1_mm>>8) & 0x00FF;

    }
    if(CCP1IE == 1 && CCP1IF == 1)
    {
       CCP1IF = 0;
       //LED2_Toggle();
       dist_2_mm = (((TMR0 - 15781)*10)/29);
       buffer[2] = dist_2_mm & 0x00FF;
       buffer[3] = (dist_2_mm>>8) & 0x00FF;

    }
    if(CCP2IE == 1 && CCP2IF == 1)
    {
       CCP2IF = 0;
       LED2_Toggle();
       dist_3_mm = (((TMR0 - 15781)*10)/29);
       buffer[4] = dist_3_mm & 0x00FF;
       buffer[5] = (dist_3_mm>>8) & 0x00FF;
    }
}

void main(void) {
    SYSTEM_Initialize();
    I2CInit(SLAVE, PIC_ADDR);
    while(1)
    {

    }
}
