/* 
 * File:   cells.h
 * Author: bemcg
 *
 * Created on February 23, 2023, 12:50 PM
 */

#ifndef CELLS_H
#define	CELLS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define MAX_CELLS   6
#define STORAGE_VOLTAGE 3.85
#define DISCHARGE_TIME  30  //number of seconds per discharge interval
#define FINISH_COUNT    4  //Number of discharge intervals to finish 4 * 30 = 2 minutes
    
    extern int numCells;
    extern double cellVoltages[MAX_CELLS];
    void getCellVoltages(void);
    void cellDischargeOn(int cell);
    void cellDischargeOff(int cell);
    void allCellsOff(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* CELLS_H */

