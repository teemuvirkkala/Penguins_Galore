#include "main.h"

/*Basic movement commands in order of NE,E,SE,SW,W,NW

-Currently only checking for Penguin ID and then move the Penguin for amount of Spaces
-Checking function CheckMove() checks that the tile isn't a 0 and that there are no penguins on the tile
-Feedback for the player if the move is invalid? Currently if the move isn't possible it's not completed (partial movement is possible)
-Amount of arguments? Do we need to pass FishArray for the check function?*/

void MovePengNE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(PengArray[idRow][1] % 2) {
            //Check if the move is possible before executing
            if(CheckMove(--Row, ++Col, NumOfCols, FishArray, AllPengs, PengArray) == 1) {
                (PengArray[idRow][1])--; //X -= 1
                (PengArray[idRow][2])++; //Y += 1
            }
        } else {
            if(CheckMove(--Row, Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
                (PengArray[idRow][1])--; //Y += 1
        }
    }
}


void MovePengE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        //Check if the move is possible before executing
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(CheckMove(Row, ++Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
            (PengArray[idRow][2])++; //Y += 1
    }
}

void MovePengSE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        //Check if the move is possible before executing
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(PengArray[idRow][1] % 2) {
            if(CheckMove(++Row, ++Col, NumOfCols, FishArray, AllPengs, PengArray) == 1) {
                (PengArray[idRow][1])++;
                (PengArray[idRow][2])++;
            }
        } else {
            if(CheckMove(++Row, Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
                (PengArray[idRow][1])++;
        }
    }
}

void MovePengSW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i,idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        //Check if the move is possible before executing
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(PengArray[idRow][1] % 2 == 0) {
            if(CheckMove(++Row, --Col, NumOfCols, FishArray, AllPengs, PengArray) == 1) {
                (PengArray[idRow][1])++;
                (PengArray[idRow][2])--;
            }
        } else {
            if(CheckMove(++Row, Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
                (PengArray[idRow][1])++;
        }
    }
}

void MovePengW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        //Check if the move is possible before executing
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(CheckMove(Row, --Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
                (PengArray[idRow][2])--;
    }
}

void MovePengNW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]) {

    int i, idRow, Row, Col;

    idRow = WhichPenguin(ID, AllPengs, PengArray); //Search for the right row in the array so we don't have to check it every incrementation of Spaces

    for(i=0; i < Spaces; i++) {
        //Check if the move is possible before executing
        Row = PengArray[idRow][1];
        Col = PengArray[idRow][2];

        if(PengArray[idRow][1] % 2 == 0) {
            if(CheckMove(--Row, --Col, NumOfCols, FishArray, AllPengs, PengArray) == 1) {
                (PengArray[idRow][1])--;
                (PengArray[idRow][2])--;
            }
        } else {
            if(CheckMove(--Row, Col, NumOfCols, FishArray, AllPengs, PengArray) == 1)
                (PengArray[idRow][1])--;
        }
    }
}
