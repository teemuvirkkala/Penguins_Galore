#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef __unix__
# include <unistd.h>
#elif defined _WIN32
# include <windows.h>
#define sleep(x) Sleep(1000 * x)
#endif

#define TURNBYTURN_MODE 1

/*TURNBYTURN_MODE, Wait the player to press anything every DrawScreen() and clear the screen,
easier to follow longer games, but still gives us the opportunity to see full output, windows only*/

//Function prototypes
void MapGenerator(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols]);
void DrawBoard(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void PosPeng(int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
int CheckPeng(int, int, int PengRows, int PengArray[PengRows][3]);

//Movement function prototypes
void MovePengNE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void MovePengE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void MovePengSE(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void MovePengSW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void MovePengW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
void MovePengNW(int, int, int NumOfRows, int NumOfCols, int FishArray[NumOfRows][NumOfCols], int PengRows, int PengArray[PengRows][3]);
