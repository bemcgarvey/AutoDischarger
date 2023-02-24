#include "mcc_generated_files/mcc.h"
#include "cells.h"

enum {
    STORAGE_MODE = 0, BALANCE_MODE = 1
} mode;

void main(void) {
    int seconds = 0;
    bool allDone;
    mode = STORAGE_MODE;
    SYSTEM_Initialize();
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
    printf("Starting %d cells\r\n", numCells);
    while (1) {
        if (seconds == 0) {
            allCellsOff();
            __delay_ms(50);
            getCellVoltages();
            for (int i = 0; i < numCells; ++i) {
                printf("%.2f ", cellVoltages[i]);
            }
            printf("\r\n");
            allDone = true;
            for (int i = 0; i < numCells; ++i) {
                if (cellVoltages[i] > STORAGE_VOLTAGE) {
                    cellDischargeOn(i);
                    allDone = false;
                }
            }
        }
        if (allDone) {
            //TODO put all this in a function void powerOff()
            allCellsOff();
            //TODO configure for lowest power:
            // ADC off, VREG at lowest power, LED off, OPAMPs off, UART off
            // Internal oscillator to low freq?
            // Should analog inputs be switched to outputs and grounded?
            INTERRUPT_GlobalInterruptHighDisable();
            Sleep();
            Nop();
            while (1) {
                LED_Toggle();
                __delay_ms(100);
            }
        }
        LED_Toggle();
        __delay_ms(1000);
        ++seconds;
        if (seconds == 60) {
            seconds = 0;
        }
    }
}
/**
 End of File
 */