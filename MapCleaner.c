#include "main.h"

void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {
    int i,j;

    for (i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            FishArray[i][j] = 0;
        }
    }
}
