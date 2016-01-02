#include "main.h"

//PosPeng function to be used in playing algorithms. Player inputs Row and Col where he wishes to place his/her penguin.
//PosPeng will input the penguin to the next free line and an ID for it. Return 1 if successful and 0 if Penguin can't be placed on given tile.

int PosPeng(int Row, int Col, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i;

    if(Row < 0 || Row > NumOfRows )
        return 0;
    else if(Col < 0 || Col > NumOfCols)
        return 0;

    for(i = 0; i < AllPengs; i++) {
        if(PengArray[i][0] == 0) {
            if(FishArray[Row][Col] == 1 && CheckPeng(Row, Col, AllPengs, PengArray) == 0) {
                PengArray[i][0] = i+1;
                PengArray[i][1] = Row;
                PengArray[i][2] = Col;
                return 1;
            }
        }
    }
    return 0;
}

//I left this function here because it can still be used in testing. PosPeng is the actual function to be used in playing algorithms.

void PosPeng2(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i,j,a;
    int found = 0;

    for(a = 0; a < AllPengs; a++) {
        for(i = 0; i < NumOfRows; i++) {
            for(j = 0; j < NumOfCols; j++) {
                if(FishArray[i][j] == 1 && CheckPeng(i, j, AllPengs, PengArray) == 0) {
                    PengArray[a][0] = a + 1; //Penguin ID
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
