#include "main.h"

void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {

    srand(time(NULL));         // Generator of number of fishes
    int i,j;

    for (i=1;i<NumOfRows-1;i++) {
        for(j=1;j<NumOfCols-1;j++) {
                FishArray[i][j]=((rand()%3)+1);
            }
    }
}
