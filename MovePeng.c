#include "main.h"

/*Basic movement commands in order of NE,E,SE,SW,W,NW

-Checking function CheckTile() checks that the tile isn't a 0 and that there are no penguins on the tile.
-Checking function CheckMove() checks all the tiles before we actually move at all. If there's a penguin or a zero on the path we don't move at all!
-Feedback for the player if the move is invalid?*/

void MovePengNE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 1, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        for(i = 0; i < Spaces; i++) {
            if(PengArray[idRow][1] % 2) {
                (PengArray[idRow][1])--; //X -= 1
                (PengArray[idRow][2])++; //Y += 1
            } else {
                (PengArray[idRow][1])--; //X -= 1
            }
        }
    } //if the move fails inform player somehow?
}


void MovePengE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 2, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        PengArray[idRow][2] += Spaces; //Y += Spaces
    }
}

void MovePengSE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 3, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        for(i = 0; i < Spaces; i++) {
            if(PengArray[idRow][1] % 2) {
                (PengArray[idRow][1])++; //X += 1
                (PengArray[idRow][2])++; //Y += 1
            } else {
                (PengArray[idRow][1])++; //Y += 1
            }
        }
    } //if the move fails inform player somehow?
}

void MovePengSW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 4, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        for(i = 0; i < Spaces; i++) {
            if(PengArray[idRow][1] % 2 == 0) {
                (PengArray[idRow][1])++; //X += 1
                (PengArray[idRow][2])--; //Y -= 1
            } else {
                (PengArray[idRow][1])++; //Y += 1
            }
        }
    } //if the move fails inform player somehow?
}

void MovePengW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 5, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        PengArray[idRow][2] -= Spaces;
    }
}

void MovePengNW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces
    Row = PengArray[idRow][1];
    Col = PengArray[idRow][2];

    if(CheckMove(idRow, 6, Spaces, Row, Col, NumOfCols, FishArray, AllPengs, PengArray)) {
        FishArray[Row][Col] = 0;
        for(i = 0; i < Spaces; i++) {
            if(PengArray[idRow][1] % 2 == 0) {
                (PengArray[idRow][1])--; //X -= 1
                (PengArray[idRow][2])--; //Y -= 1
            } else {
                (PengArray[idRow][1])--; //Y += 1
            }
        }
    } //if the move fails inform player somehow?
}
