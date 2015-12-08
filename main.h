#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif

#define TURNBYTURN_MODE
//#define DEBUG_MODE

/*TURNBYTURN_MODE, Wait the player to press anything every DrawScreen() and clear the screen,
easier to follow longer games, but still gives us the opportunity to see full output, windows only*/

//Commands for user//
    //Moving//
    void UserMoveNE (int ID, int Spaces);
    void UserMoveE (int ID, int Spaces);
    void UserMoveSE (int ID, int Spaces);
    void UserMoveSW (int ID, int Spaces);
    void UserMoveNW (int ID, int Spaces);
    void UserMoveW (int ID, int Spaces);













//BasicFunctions
void InitArray(int Rows, int Cols, int a[Rows][Cols]);
void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int PosPeng(int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void PosPeng2(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);

//CheckingFunctions
int CheckPeng(int, int, int AllPengs, int PengArray[AllPengs][3]);
int CheckBoard(int, int, int NumOfCols, int FishArray[][NumOfCols]);
int CheckTile(int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int CheckMove(int, int, int, int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int CheckEnd(int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int WhichPenguin(int, int AllPengs, int PengArray[AllPengs][3]);

//Movement function prototypes
void MovePengNE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void MovePengE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void MovePengSE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void MovePengSW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void MovePengW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void MovePengNW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
