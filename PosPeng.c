#include "main.h"

//Simple example on how to create PosPeng function for the player

void PosPeng(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i,j,a;
    int found = 0;

    for(a=1; a <= AllPengs; a++) {
        for(i=0; i < NumOfRows; i++) {
            for(j=0; j < NumOfCols; j++) {
                if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray)) {
                    PengArray[a][0] = a+1; //Penguin ID
                    PengArray[a][1] = i; //X coordinate for penguin
                    PengArray[a][2] = j; //Y coordinate for penguin
                    found = 1;
                    break;
                }
            }
            if(found == 1)
                break;
        }
        found = 0;
    }
}
