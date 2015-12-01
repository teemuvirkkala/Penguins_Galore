#include "main.h"

//Init array is a placeholder function just so other functions work properly. This should be done with calloc instead.

void InitArray(int Rows, int Cols, int a[Rows][Cols]) {
    int i,j;

    for(i = 0; i < Rows; i++) {
        for(j = 0; j < Cols; j++) {
            a[i][j] = 0;
        }
    }
}

void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {

    srand(time(NULL));         // Generator of number of fishes
    int i,j;

    for (i=1;i<NumOfRows-1;i++) {
        for(j=1;j<NumOfCols-1;j++) {
                FishArray[i][j]=((rand()%3)+1);
            }
    }
}
