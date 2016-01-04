#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#endif

#define MAX_LEN 128 // for ascii printing

#define TURNBYTURN_MODE
//#define DEBUG_MODE

/*TURNBYTURN_MODE, Wait the player to press anything every DrawScreen() and clear the screen,
easier to follow longer games, but still gives us the opportunity to see full output, windows only*/

//Preaparation for pointers to functions
typedef int (*Pointer)(int,int,int**,int,int**);

//Commands for user//
//Manual//
int UserEnterDir(int i, int, int**, int, int**);
int UserEnterCrdY(int i, int, int**, int, int**);
int UserEnterCrdX(int i, int, int**, int, int**);
int UserEnterNumOfSpaces(int i, int, int**, int, int**);
int UserEnterPengID(int i, int, int**, int, int**);

//Dummy
int DummyDir(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int DummyCrdX(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int DummyCrdY(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int DummySpaces(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int DummyPengID(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);

//BasicFunctions
void PengCleaner(int AllPengs, int PengArray[AllPengs][3]);
void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void MapCleaner(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void PrintCoords(int, int, int AllPengs, int PengArray[AllPengs][3]);
void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int PosPeng(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void PosPeng2(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
void Intro();
int TurnCounter(int);
void AsciiArtPrinter(FILE *fptr);
int PlayGame(int P1ID, Pointer PointerX1, Pointer PointerY1, Pointer PointerDir1, Pointer PointerSpaces1, Pointer PointerPengID1, int P2ID, Pointer PointerX2, Pointer PointerY2, Pointer PointerDir2, Pointer PointerSpaces2, Pointer PointerPengID2);
int Score (int, int, int, int NumOfCols, int FishArray[][NumOfCols]);

//Saving and Loading
int SaveBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3], int, int);
int LoadBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int AllPengs, int PengArray[AllPengs][3]);
int LoadRoC(int);

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
