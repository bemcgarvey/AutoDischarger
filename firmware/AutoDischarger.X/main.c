#include "mcc_generated_files/mcc.h"
#include "cells.h"

#define VERSION "1.0" 
enum {
    STORAGE_MODE = 0, BALANCE_MODE = 1
} mode;

bool modeChange = false;

void powerOff(void);
void buttonPressed(void);
void terminateNormal(void);
void terminateWDT(void);
void terminateBadCell(void);

void main(void) {
    double targetVoltage;
    double lowestCell;
    uint8_t allDoneCount = 0;
    uint8_t seconds = 0;
    mode = BALANCE_MODE;
    SYSTEM_Initialize();
    INT0_SetInterruptHandler(buttonPressed);
    LED_SetLow();
    SHDN_SetLow();
    allCellsOff();
    if (PCON0bits.RWDT == 0) { //Check for WDT reset
        terminateWDT();
    }
    PCON0bits.RWDT = 1;
    numCells = MAX_CELLS;
    __delay_ms(500);
    getCellVoltages();
    for (int i = 0; i < MAX_CELLS; ++i) {
        if (cellVoltages[i] < 3.0) {
            numCells = i;
            break;
        }
    }
    lowestCell = MAX_CELL_VOLTAGE;
    for (int i = 0; i < numCells; ++i) {
        if (cellVoltages[i] < lowestCell) {
            lowestCell = cellVoltages[i];
        }
    }
    targetVoltage = lowestCell;
    printf("Starting firmware version %s\r\n", VERSION);
    printf("%d cells\r\n", numCells);
    printf("Low cell = %.3f\r\n", lowestCell);
    INTERRUPT_GlobalInterruptHighEnable();
    while (1) {
        if (modeChange) {
            modeChange = false;
            seconds = 0;
            if (mode == STORAGE_MODE) {
                targetVoltage = STORAGE_VOLTAGE;
            } else if (mode == BALANCE_MODE) {
                allCellsOff();
                __delay_ms(50);
                getCellVoltages();
                lowestCell = MAX_CELL_VOLTAGE;
                for (int i = 0; i < numCells; ++i) {
                    if (cellVoltages[i] < lowestCell) {
                        lowestCell = cellVoltages[i];
                    }
                }
                targetVoltage = lowestCell;
            }
        }
        if (seconds == 0) {
            allCellsOff();
            __delay_ms(50);
            getCellVoltages();
            //Check for bad cells
            for (int i = 0; i < numCells; ++i) {
                if (cellVoltages[i] < MIN_CELL_VOLTAGE 
                        || cellVoltages[i] >= MAX_CELL_VOLTAGE) {
                    terminateBadCell();
                }
            }
            for (int i = 0; i < numCells; ++i) {
                printf("%.3f ", cellVoltages[i]);
            }
            printf("target = %.3f\r\n", targetVoltage);
            ++allDoneCount;
            for (int i = 0; i < numCells; ++i) {
                if (cellVoltages[i] > targetVoltage) {
                    cellDischargeOn(i);
                    allDoneCount = 0;
                }
            }
            if (allDoneCount >= FINISH_COUNT) {
                terminateNormal();
            }
        }
        if (mode == STORAGE_MODE) {
            LED_Toggle();
            __delay_ms(1000);
        } else if (mode == BALANCE_MODE) {
            LED_SetHigh();
            __delay_ms(100);
            LED_SetLow();
            __delay_ms(100);
            LED_SetHigh();
            __delay_ms(100);
            LED_SetLow();
            __delay_ms(700);
        }
        ++seconds;
        if (seconds >= DISCHARGE_TIME) {
            seconds = 0;
        }
        ClrWdt();
    }
}

void powerOff(void) {
    allCellsOff();
    LED_SetLow();
    SHDN_SetHigh();
    ADCON0bits.ADON = 0;
    U1CON1bits.ON = 0;
    PMD3bits.U1MD = 1; //Disable UART1 and ADC
    PMD2bits.ADCMD = 1;
    VREGCON = 0b10;
    OSCCON1bits.NOSC = 0b101; //Switch to LFINTOSC
    while (OSCCON3bits.ORDY != 1);
}

void buttonPressed(void) {
    __delay_ms(50);
    if (PORTCbits.RC6 == 0) {
        modeChange = true;
        if (mode == STORAGE_MODE) {
            mode = BALANCE_MODE;
        } else if (mode == BALANCE_MODE) {
            mode = STORAGE_MODE;
        }
    }
}

//These terminate functions do not return.

void terminateNormal(void) {
    powerOff();
    INTERRUPT_GlobalInterruptHighDisable();
    Sleep();
    Nop();
    LED_SetHigh();
    while (1) {
        __delay_us(1000); //Actually 1s
        ClrWdt();
    }
}

void terminateWDT(void) {
    powerOff();
    Sleep();
    Nop();
    while (1) {
        LED_Toggle();
        __delay_us(100); //This is actually 100ms since clock is now slower
        ClrWdt();
    }
}

void terminateBadCell(void) {
    powerOff();
    INTERRUPT_GlobalInterruptHighDisable();
    Sleep();
    Nop();
    while (1) {
        for (int i = 0; i < 3; ++i) {
            LED_SetHigh();
            __delay_us(100);
            LED_SetLow();
            __delay_us(100);
        }
        ClrWdt();
        __delay_us(1000); //Actually 1s
        ClrWdt();
    }
}