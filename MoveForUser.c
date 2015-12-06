#include "main.h"
#include "global.h"

int NumOfRows=NumberOfRows, NumOfCols=NumberOfColumns;
//set of functions of moves for user algorhitm. They take direction, amount of spaces and number of peng and then are used as bridge to
//call specific function with moe args (saving coding time for user)

void UserMoveNE (int ID, int Spaces){
MovePengNE(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

void UserMoveE (int ID, int Spaces){
MovePengE(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

void UserMoveSE (int ID, int Spaces){
MovePengSE(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

void UserMoveSW (int ID, int Spaces){
MovePengSW(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

void UserMoveW (int ID, int Spaces){
MovePengW(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

void UserMoveNW (int ID, int Spaces){
MovePengNW(ID, Spaces, NumOfRows, NumOfCols, FishArray[NumOfRows][NumOfCols], AllPengs, PengArray[AllPengs][3])
}

