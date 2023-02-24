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
    for (int i = 0; i < 6; ++i) {
        printf("%.2f ", cellVoltages[i]);
    }
    printf("\r\n");
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
            allCellsOff();
            //TODO turn everything off and go to sleep
            // use button to wake up.
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