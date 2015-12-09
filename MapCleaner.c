#include "main.h"

void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {
    int i,j;

    for (i = 0; i < NumOfRows; i++) {
        for(j = 0; j < NumOfCols; j++) {
            FishArray[i][j] = 0;
        }
    }
}

void PengCleaner(int AllPengs, int PengArray[AllPengs][3])
{
    int i;
        for(i = 0; i < AllPengs; i++){
        PengArray[i][0] = 0;
        PengArray[i][1] = 0;
        PengArray[i][2] = 0;
    }
}
