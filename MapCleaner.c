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

//Init array is a placeholder function just so other functions work properly. This should be done with calloc instead.

void InitArray(int Rows, int Cols, int a[Rows][Cols]) {
    int i,j;

    for(i = 0; i < Rows; i++) {
        for(j = 0; j < Cols; j++) {
            a[i][j] = 0;
        }
    }
}
