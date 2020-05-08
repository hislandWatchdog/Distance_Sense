/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File: pin_manager.h
 * Author: Juan de Dios Duuran
 * Comments:
 * Revision history: V1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef PIN_MANAGER_H
#define	PIN_MANAGER_H

#include <xc.h> // include processor files - each processor file is guarded.  
/*#define LED1_SetOn()            LATA6 = 0
#define LED1_SetOff()           LATA6 = 1
#define LED1_Toggle()           LATA6 ^= 1
#define LED1_SetDigitalInput()  TRISA6 = 1
#define LED1_SetDigitalOutput() TRISA6 = 0*/

#define LED2_SetOn()            LATC0 = 0
#define LED2_SetOff()           LATC0 = 1
#define LED2_Toggle()           LATC0 ^= 1
#define LED2_SetDigitalInput()  TRISC0 = 1
#define LED2_SetDigitalOutput() TRISC0 = 0

#define Trigger1_SetOn()            LATA0 = 1
#define Trigger1_SetOff()           LATA0 = 0
#define Trigger1_Toggle()           LATA0 ^= 1
#define Trigger1_SetDigitalInput()  TRISA0 = 1
#define Trigger1_SetDigitalOutput() TRISA0 = 0

#define Trigger2_SetOn()            LATA1 = 1
#define Trigger2_SetOff()           LATA1 = 0
#define Trigger2_Toggle()           LATA1 ^= 1
#define Trigger2_SetDigitalInput()  TRISA1 = 1
#define Trigger2_SetDigitalOutput() TRISA1 = 0

#define Trigger3_SetOn()            LATA2 = 1
#define Trigger3_SetOff()           LATA2 = 0
#define Trigger3_Toggle()           LATA2 ^= 1
#define Trigger3_SetDigitalInput()  TRISA2 = 1
#define Trigger3_SetDigitalOutput() TRISA2 = 0



void PIN_MANAGER_Initialize (void);

#endif	/* PIN_MANAGER_H */

