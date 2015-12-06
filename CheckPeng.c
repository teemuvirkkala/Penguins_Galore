#include "main.h"

//Returns 0 if there's a penguin in given coordinates and 1 if the space is free

int CheckPeng(int Row, int Col, int AllPengs, int PengArray[AllPengs][3]) {

    int i;

    for(i=0; i < AllPengs; i++) {
        if(PengArray[i][0] > 0 && PengArray[i][1] == Row && PengArray[i][2] == Col) {
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

//Check if it's possible to use the tile, 1 = true, 0 = false

int CheckTile(int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    //Check if it's possible to move to the tile == the tile isn't a zero
    if(CheckBoard(Row, Col, NumOfCols, FishArray) != 0) {
        //Check if there's already a penguin on the tile
        if(CheckPeng(Row, Col, AllPengs, PengArray)) {
            return 1;
        }
    }
    return 0;
}

//Check if it's possible to move, 1 = true, 0 = false, checks the whole move at once tile by tile.

int CheckMove(int idRow, int Dir, int Spaces, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, canMove = 0;
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    for(i = 0; i < Spaces; i++) {
        if(Row % 2) {
            switch(Dir) { //Default the switch to what?
                case 1: //NE
                    Row--;
                    Col++;
                    break;
                case 2: //E
                    Col++;
                    break;
                case 3: //SE
                    Row++;
                    Col++;
                    break;
                case 4: //SW
                    Row++;
                    break;
                case 5:  //W
                    Col--;
                    break;
                case 6:  //NW
                    Row--;
                    break;
            }
            if(CheckTile(Row, Col, NumOfCols, FishArray, AllPengs, PengArray))
                canMove = 1;
            else
                canMove = 0;
        } else {
            switch(Dir) {
                case 1: //NE
                    Row--;
                    break;
                case 2: //E
                    Col++;
                    break;
                case 3: //SE
                    Row++;
                    break;
                case 4: //SW
                    Row++;
                    Col--;
                    break;
                case 5:  //W
                    Col--;
                    break;
                case 6:  //NW
                    Row--;
                    Col--;
                    break;
            }
            if(CheckTile(Row, Col, NumOfCols, FishArray, AllPengs, PengArray))
                canMove = 1;
            else
                canMove = 0;
        }
    }
    return canMove;
}

int CheckEnd(int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {
    int i, j, Row, Col, GameEnd;

    for(i = 0; i < AllPengs; i++) { //Check all the penguins
        for(j = 1; j <= 6; j++) { //Check all the directions for each penguin
            Row = PengArray[i][1];
            Col = PengArray[i][1];
            if(CheckMove(i, j, 1, Row, Col, NumOfCols, FishArray, AllPengs, PengArray) == 0) {
                GameEnd = 1;
            } else {
                GameEnd = 0;
            }
        }
    }
    return GameEnd;
}

//Returns the row number of the penguin we want to move, returns -1 if the ID doesn't match any penguins

int WhichPenguin(int ID, int AllPengs, int PengArray[AllPengs][3]) {

    int i;

    for(i=0; i < AllPengs; i++) {
        if(PengArray[i][0] == ID)
            return i;
    }
    return -1;
}


