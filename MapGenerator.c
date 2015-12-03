#include "main.h"

void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]) {

    srand(time(NULL));         // Generator of number of fishes
    int i,j,RandomNumber;

    for (i=1;i<NumOfRows-1;i++) {
        for(j=1;j<NumOfCols-1;j++) {                //
                RandomNumber = rand() % 100;
    RandomNumber -= 20;
        if (RandomNumber < 0)
  FishArray[i][j]=2;
    else {
  RandomNumber -= 30;
  if (RandomNumber < 0)
    FishArray[i][j]=3;
  else
    FishArray[i][j]=1;
}
            }
    }
}
