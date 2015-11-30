#include "main.h"

void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {

    srand(time(NULL));         // Generator of number of fishes
    int i,j;

    for (i=0;i<NumOfRows;i++) {
        for(j=0;j<NumOfCols;j++) {
                FishArray[i][j]=0;
            }
    }
}

