#include "mcc_generated_files/mcc.h"
#include "cells.h"

int numCells = 0;
double cellVoltages[MAX_CELLS];

//TODO is the correction to cell 3 required for every unit or is it
// specific to this one?
double cellCalibration[MAX_CELLS] = {0.0, 0.0, 0.04, 0.0, 0.0, 0.0};

static const adcc_channel_t adcChannels[] = {VSense1, VSense2, VSense3, VSense4, VSense5, VSense6};

void getCellVoltages(void) {
    for (int i = 0; i < numCells; ++i) {
        uint16_t v = ADCC_GetSingleConversion(adcChannels[i]);
        cellVoltages[i] = v / 4095.0 * 5.0;
        cellVoltages[i] += cellCalibration[i];
    }
}

void cellDischargeOn(int cell) {
    switch (cell) {
        case 0: C1_SetHigh();
        break;
        case 1: C2_SetLow();
        break;
        case 2: C3_SetLow();
        break;
        case 3: C4_SetLow();
        break;
        case 4: C5_SetLow();
        break;
        case 5: C6_SetLow();
        break;
    }
}

void cellDischargeOff(int cell) {
    switch (cell) {
        case 0: C1_SetLow();
        break;
        case 1: C2_SetHigh();
        break;
        case 2: C3_SetHigh();
        break;
        case 3: C4_SetHigh();
        break;
        case 4: C5_SetHigh();
        break;
        case 5: C6_SetHigh();
        break;
    }
}

void allCellsOff(void) {
    C1_SetLow();
    C2_SetHigh();
    C3_SetHigh();
    C4_SetHigh();
    C5_SetHigh();
    C6_SetHigh();
}