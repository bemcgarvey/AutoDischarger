#include "mcc_generated_files/mcc.h"
#include "cells.h"

enum {
    STORAGE_MODE = 0, BALANCE_MODE = 1
} mode;

double targetVoltage;
double lowestCell;

void powerOff(void);
void buttonPressed(void);

void main(void) {
    int seconds = 0;
    bool allDone;
    mode = BALANCE_MODE;
    SYSTEM_Initialize();
    INT0_SetInterruptHandler(buttonPressed);
    LED_SetLow();
    SHDN_SetLow();
    allCellsOff();
    numCells = MAX_CELLS;
    __delay_ms(500);
    getCellVoltages();
    for (int i = 0; i < MAX_CELLS; ++i) {
        if (cellVoltages[i] < 3.0) {
            numCells = i;
            break;
        }
    }
    lowestCell = 5.0;
    for (int i = 0; i < numCells; ++i) {
        if (cellVoltages[i] < lowestCell) {
            lowestCell = cellVoltages[i];
        }
    }
    targetVoltage = lowestCell;
    printf("Starting %d cells\r\n", numCells);
    printf("Low cell = %.3f\r\n", lowestCell);
    INTERRUPT_GlobalInterruptHighEnable();
    while (1) {
        if (seconds == 0) {
            allCellsOff();
            __delay_ms(50);
            getCellVoltages();
            for (int i = 0; i < numCells; ++i) {
                printf("%.3f ", cellVoltages[i]);
            }
            printf("target = %.3f\r\n", targetVoltage);
            allDone = true;
            for (int i = 0; i < numCells; ++i) {
                if (cellVoltages[i] > targetVoltage) {
                    cellDischargeOn(i);
                    allDone = false;
                }
            }
        }
        if (allDone) {
            allCellsOff();
            powerOff();
            INTERRUPT_GlobalInterruptHighDisable();
            Sleep();
            Nop();
            while (1) {
                LED_Toggle();
                __delay_ms(100);
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
        if (seconds == 60) {
            seconds = 0;
        }
    }
}

void powerOff(void) {
    LED_SetLow();
    SHDN_SetHigh();
    ADCON0bits.ADON = 0;
    U1CON1bits.ON = 0;
    VREGCON = 0b10;
    //Switch to LFINTOSC?
    //Make analog inputs outputs and set to gnd?
}

void buttonPressed(void) {
    __delay_ms(50);
    if (mode == STORAGE_MODE) {
        mode = BALANCE_MODE;
        targetVoltage = lowestCell;
    } else if (mode == BALANCE_MODE) {
        mode = STORAGE_MODE;
        targetVoltage = STORAGE_VOLTAGE;
    }
}