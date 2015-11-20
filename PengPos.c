#include "main.h"

void PosPeng(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    int i,j;
    int found = 0;

    for(i=0; i < NumOfRows; i++) {
        for(j=0; j < NumOfCols; j++) {
            if(FishArray[i][j] == 1) {
                PengArray[0][0] = 1; //Player ID
                PengArray[0][1] = i; //X coordinate for penguin
                PengArray[0][2] = j; //Y coordinate for penguin
                found = 1;
                break;
            }
        }
        if(found == 1) {
            break;
        }

    }


}
