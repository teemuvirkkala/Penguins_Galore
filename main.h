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
#define MAX_LEN 128 // for ascii printing

#define TURNBYTURN_MODE
//#define DEBUG_MODE

/*TURNBYTURN_MODE, Wait the player to press anything every DrawScreen() and clear the screen,
easier to follow longer games, but still gives us the opportunity to see full output, windows only*/

//Preaparation for pointers to functions
typedef int (*Pointer)(int);

//Commands for user//
    //Moving//
    void UserMoveNE (int ID, int Spaces);
    void UserMoveE (int ID, int Spaces);
    void UserMoveSE (int ID, int Spaces);
    void UserMoveSW (int ID, int Spaces);
    void UserMoveNW (int ID, int Spaces);
    void UserMoveW (int ID, int Spaces);

    //Manual//
    int UserEnterDir(int i);
    int UserEnterCrdY(int i);
    int UserEnterCrdX(int i);
    int UserEnterNumOfSpaces(int i);
    int UserEnterPengID(int i);

//BasicFunctions
void PengCleaner(int AllPengs, int PengArray[AllPengs][3]);
void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void PrintCoords(int AllPengs, int PengArray[AllPengs][3]);
void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int PosPeng(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void PosPeng2(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void Intro();
void TurnCounter(int);
void AsciiArtPrinter(FILE *fptr);
int PlayGame(Pointer PointerX1, Pointer PointerY1, Pointer PointerDir1, Pointer PointerSpaces1, Pointer PointerPengID1, Pointer PointerX2, Pointer PointerY2, Pointer PointerDir2, Pointer PointerSpaces2, Pointer PointerPengID2);
void Score (int AllPengs, int idRow, int Row, int Col, int NumOfCols, int FishArray[][NumOfCols], int PengArray[AllPengs][3]);

//CheckingFunctions
int CheckPeng(int, int, int AllPengs, int PengArray[AllPengs][3]);
int CheckBoard(int, int, int NumOfCols, int FishArray[][NumOfCols]);
int CheckTile(int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int CheckMove(int, int, int, int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int CheckEnd(int NumOfCols, int FishArray[][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int WhichPenguin(int, int AllPengs, int PengArray[AllPengs][3]);

//Movement function prototypes
int MovePengNE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengSE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengSW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int MovePengNW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
