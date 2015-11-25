#include "main.h"

//Returns 0 if there's a penguin in given coordinates and 1 if the space is free

int CheckPeng(int Row, int Col, int PengRows, int PengArray[PengRows][3]) {

    int i;

    for(i=0; i < PengRows; i++) {
        if(PengArray[i][1] == Row && PengArray[i][2] == Col) {
            return 0;
        }
    }
    return 1;
}

//Returns the number of fishes in given coordinates

int CheckBoard(int Row, int Col, int NumOfCols, int FishArray[][NumOfCols]) {

    int i;
    i = FishArray[Row][Col];
    return i;
}

//Check if the players movement is possible, 1 = true, 0 = false

int CheckMove(int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int PengRows, int PengArray[PengRows][3]) {

    //Check if it's possible to move to the tile == the tile isn't a zero
    if(CheckBoard(Row, Col, NumOfCols, FishArray) != 0) {
        //Check if there's already a penguin on the tile
        if(CheckPeng(Row, Col, PengRows, PengArray)) {
            return 1;
        }
    }
    return 0;
}

//Returns the row number of the penguin we want to move

int WhichPenguin(int ID, int PengRows, int PengArray[PengRows][3]) {

    int i;

    for(i=0; i < PengRows; i++) {
        if(PengArray[i][0] == ID)
            return i;
    }
}


