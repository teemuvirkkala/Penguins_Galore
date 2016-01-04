//Commands for user//
//CheckingFunctions
int CheckPeng(int, int, int AllPengs, int PengArray[AllPengs][3]);
int CheckBoard(int, int, int NumOfCols, int FishArray[][NumOfCols]);
int CheckTile(int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int CheckMove(int, int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int WhichPenguin(int, int AllPengs, int PengArray[AllPengs][3]);

//Movement function prototypes
int MovePengNE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengSE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengSW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengNW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
