#include "mcc_generated_files/mcc.h"
#include "cells.h"

enum {
    STORAGE_MODE = 0, BALANCE_MODE = 1
} mode;

bool modeChange = false;

void powerOff(void);
void buttonPressed(void);

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
        if (modeChange) {
            modeChange = false;
            seconds = 0;
            if (mode == STORAGE_MODE) {
                targetVoltage = STORAGE_VOLTAGE;
            } else if (mode == BALANCE_MODE) {
                allCellsOff();
                __delay_ms(50);
                getCellVoltages();
                lowestCell = 5.0;
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
                //All done
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
    }
}

void powerOff(void) {
    LED_SetLow();
    SHDN_SetHigh();
    ADCON0bits.ADON = 0;
    U1CON1bits.ON = 0;
    VREGCON = 0b10;
    //Switch to LFINTOSC?
}

void buttonPressed(void) {
    __delay_ms(50);
    if (Button_GetValue() == 0) {
        modeChange = true;
        if (mode == STORAGE_MODE) {
            mode = BALANCE_MODE;
        } else if (mode == BALANCE_MODE) {
            mode = STORAGE_MODE;
        }
    }
}