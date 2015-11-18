#include <time.h>
#include <stdio.h>
#include <stdlib.h>

//Function prototypes
void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void PosPeng(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
