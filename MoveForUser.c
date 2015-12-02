#include "main.h"

extern int NumberOfRows, NumberOfColumns, AllPengs;




//set of functions of moves for user algorhitm. They take direction, amount of spaces and number of peng and then are used as bridge to
//call specific function with moe args (saving coding time for user)

void UserMoveNE (int ID, int Spaces){
MovePengNE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

void UserMoveE (int ID, int Spaces){
MovePengE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

void UserMoveSE (int ID, int Spaces){
MovePengSE(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

void UserMoveSW (int ID, int Spaces){
MovePengSW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

void UserMoveW (int ID, int Spaces){
MovePengW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

void UserMoveNW (int ID, int Spaces){
MovePengNW(int ID, int Spaces, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3])
}

