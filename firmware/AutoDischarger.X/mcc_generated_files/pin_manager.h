/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F15Q40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()              PORTAbits.RA0
#define RA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetPullup()             do { WPUAbits.WPUA0 = 1; } while(0)
#define RA0_ResetPullup()           do { WPUAbits.WPUA0 = 0; } while(0)
#define RA0_SetAnalogMode()         do { ANSELAbits.ANSELA0 = 1; } while(0)
#define RA0_SetDigitalMode()        do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA1 procedures
#define RA1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RA1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RA1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RA1_GetValue()              PORTAbits.RA1
#define RA1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RA1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RA1_SetPullup()             do { WPUAbits.WPUA1 = 1; } while(0)
#define RA1_ResetPullup()           do { WPUAbits.WPUA1 = 0; } while(0)
#define RA1_SetAnalogMode()         do { ANSELAbits.ANSELA1 = 1; } while(0)
#define RA1_SetDigitalMode()        do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set SHDN aliases
#define SHDN_TRIS                 TRISAbits.TRISA2
#define SHDN_LAT                  LATAbits.LATA2
#define SHDN_PORT                 PORTAbits.RA2
#define SHDN_WPU                  WPUAbits.WPUA2
#define SHDN_OD                   ODCONAbits.ODCA2
#define SHDN_ANS                  ANSELAbits.ANSELA2
#define SHDN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SHDN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SHDN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SHDN_GetValue()           PORTAbits.RA2
#define SHDN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SHDN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SHDN_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SHDN_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SHDN_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define SHDN_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define SHDN_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define SHDN_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set VSense2 aliases
#define VSense2_TRIS                 TRISAbits.TRISA4
#define VSense2_LAT                  LATAbits.LATA4
#define VSense2_PORT                 PORTAbits.RA4
#define VSense2_WPU                  WPUAbits.WPUA4
#define VSense2_OD                   ODCONAbits.ODCA4
#define VSense2_ANS                  ANSELAbits.ANSELA4
#define VSense2_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define VSense2_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define VSense2_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define VSense2_GetValue()           PORTAbits.RA4
#define VSense2_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define VSense2_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define VSense2_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define VSense2_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define VSense2_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define VSense2_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define VSense2_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define VSense2_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set VSense1 aliases
#define VSense1_TRIS                 TRISAbits.TRISA5
#define VSense1_LAT                  LATAbits.LATA5
#define VSense1_PORT                 PORTAbits.RA5
#define VSense1_WPU                  WPUAbits.WPUA5
#define VSense1_OD                   ODCONAbits.ODCA5
#define VSense1_ANS                  ANSELAbits.ANSELA5
#define VSense1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define VSense1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define VSense1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define VSense1_GetValue()           PORTAbits.RA5
#define VSense1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define VSense1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define VSense1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define VSense1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define VSense1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define VSense1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define VSense1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define VSense1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set VSense6 aliases
#define VSense6_TRIS                 TRISBbits.TRISB4
#define VSense6_LAT                  LATBbits.LATB4
#define VSense6_PORT                 PORTBbits.RB4
#define VSense6_WPU                  WPUBbits.WPUB4
#define VSense6_OD                   ODCONBbits.ODCB4
#define VSense6_ANS                  ANSELBbits.ANSELB4
#define VSense6_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define VSense6_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define VSense6_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define VSense6_GetValue()           PORTBbits.RB4
#define VSense6_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define VSense6_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define VSense6_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define VSense6_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define VSense6_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define VSense6_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define VSense6_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define VSense6_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set VSense5 aliases
#define VSense5_TRIS                 TRISBbits.TRISB5
#define VSense5_LAT                  LATBbits.LATB5
#define VSense5_PORT                 PORTBbits.RB5
#define VSense5_WPU                  WPUBbits.WPUB5
#define VSense5_OD                   ODCONBbits.ODCB5
#define VSense5_ANS                  ANSELBbits.ANSELB5
#define VSense5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define VSense5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define VSense5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define VSense5_GetValue()           PORTBbits.RB5
#define VSense5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define VSense5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define VSense5_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define VSense5_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define VSense5_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define VSense5_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define VSense5_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define VSense5_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set VSense4 aliases
#define VSense4_TRIS                 TRISBbits.TRISB6
#define VSense4_LAT                  LATBbits.LATB6
#define VSense4_PORT                 PORTBbits.RB6
#define VSense4_WPU                  WPUBbits.WPUB6
#define VSense4_OD                   ODCONBbits.ODCB6
#define VSense4_ANS                  ANSELBbits.ANSELB6
#define VSense4_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define VSense4_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define VSense4_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define VSense4_GetValue()           PORTBbits.RB6
#define VSense4_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define VSense4_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define VSense4_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define VSense4_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define VSense4_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define VSense4_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define VSense4_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define VSense4_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set VSense3 aliases
#define VSense3_TRIS                 TRISBbits.TRISB7
#define VSense3_LAT                  LATBbits.LATB7
#define VSense3_PORT                 PORTBbits.RB7
#define VSense3_WPU                  WPUBbits.WPUB7
#define VSense3_OD                   ODCONBbits.ODCB7
#define VSense3_ANS                  ANSELBbits.ANSELB7
#define VSense3_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define VSense3_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define VSense3_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define VSense3_GetValue()           PORTBbits.RB7
#define VSense3_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define VSense3_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define VSense3_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define VSense3_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define VSense3_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define VSense3_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define VSense3_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define VSense3_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set C6 aliases
#define C6_TRIS                 TRISCbits.TRISC0
#define C6_LAT                  LATCbits.LATC0
#define C6_PORT                 PORTCbits.RC0
#define C6_WPU                  WPUCbits.WPUC0
#define C6_OD                   ODCONCbits.ODCC0
#define C6_ANS                  ANSELCbits.ANSELC0
#define C6_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define C6_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define C6_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define C6_GetValue()           PORTCbits.RC0
#define C6_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define C6_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define C6_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define C6_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define C6_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define C6_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define C6_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define C6_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set C4 aliases
#define C4_TRIS                 TRISCbits.TRISC1
#define C4_LAT                  LATCbits.LATC1
#define C4_PORT                 PORTCbits.RC1
#define C4_WPU                  WPUCbits.WPUC1
#define C4_OD                   ODCONCbits.ODCC1
#define C4_ANS                  ANSELCbits.ANSELC1
#define C4_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define C4_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define C4_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define C4_GetValue()           PORTCbits.RC1
#define C4_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define C4_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define C4_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define C4_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define C4_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define C4_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define C4_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define C4_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set C5 aliases
#define C5_TRIS                 TRISCbits.TRISC2
#define C5_LAT                  LATCbits.LATC2
#define C5_PORT                 PORTCbits.RC2
#define C5_WPU                  WPUCbits.WPUC2
#define C5_OD                   ODCONCbits.ODCC2
#define C5_ANS                  ANSELCbits.ANSELC2
#define C5_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define C5_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define C5_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define C5_GetValue()           PORTCbits.RC2
#define C5_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define C5_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define C5_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define C5_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define C5_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define C5_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define C5_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define C5_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set C2 aliases
#define C2_TRIS                 TRISCbits.TRISC3
#define C2_LAT                  LATCbits.LATC3
#define C2_PORT                 PORTCbits.RC3
#define C2_WPU                  WPUCbits.WPUC3
#define C2_OD                   ODCONCbits.ODCC3
#define C2_ANS                  ANSELCbits.ANSELC3
#define C2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define C2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define C2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define C2_GetValue()           PORTCbits.RC3
#define C2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define C2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define C2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define C2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define C2_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define C2_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define C2_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define C2_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set C1 aliases
#define C1_TRIS                 TRISCbits.TRISC4
#define C1_LAT                  LATCbits.LATC4
#define C1_PORT                 PORTCbits.RC4
#define C1_WPU                  WPUCbits.WPUC4
#define C1_OD                   ODCONCbits.ODCC4
#define C1_ANS                  ANSELCbits.ANSELC4
#define C1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define C1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define C1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define C1_GetValue()           PORTCbits.RC4
#define C1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define C1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define C1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define C1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define C1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define C1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define C1_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define C1_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set C3 aliases
#define C3_TRIS                 TRISCbits.TRISC5
#define C3_LAT                  LATCbits.LATC5
#define C3_PORT                 PORTCbits.RC5
#define C3_WPU                  WPUCbits.WPUC5
#define C3_OD                   ODCONCbits.ODCC5
#define C3_ANS                  ANSELCbits.ANSELC5
#define C3_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define C3_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define C3_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define C3_GetValue()           PORTCbits.RC5
#define C3_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define C3_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define C3_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define C3_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define C3_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define C3_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define C3_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define C3_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC7
#define LED_LAT                  LATCbits.LATC7
#define LED_PORT                 PORTCbits.RC7
#define LED_WPU                  WPUCbits.WPUC7
#define LED_OD                   ODCONCbits.ODCC7
#define LED_ANS                  ANSELCbits.ANSELC7
#define LED_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LED_GetValue()           PORTCbits.RC7
#define LED_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/