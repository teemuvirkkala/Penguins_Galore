#include <windows.h>
#include <stdio.h>

int UserEnterCrdX(int i)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int x;
    if (i%2==0) {
            SetConsoleTextAttribute(hConsole, 14);
    printf("Player1\n");}

    else {
            SetConsoleTextAttribute(hConsole, 12);
    printf("Player2\n");}
    printf("Enter row of your %i penguin: \n", i+1);
        SetConsoleTextAttribute(hConsole, 7);
    scanf("%i", &x);
    return x;
}

int UserEnterCrdY(int i)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int y;
    if (i%2==0) {
            SetConsoleTextAttribute(hConsole, 14);
    printf("Player1\n");}

    else {
            SetConsoleTextAttribute(hConsole, 12);
    printf("Player2\n");}
    printf("Enter column of your %i penguin: \n", i+1);
        SetConsoleTextAttribute(hConsole, 7);
    scanf("%i", &y);
    return y;
}

int UserEnterNumOfSpaces(int i)
{
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int Spaces;
    //P1
    if(i%2!=0){
    SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer1:");
    printf("\nEnter number of spaces: \n");}
    else {//P2
        SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer2:");
    printf("\nEnter number of spaces: \n");}
    scanf("%i", &Spaces);
    return Spaces;
}

int UserEnterDir(int i)
{
   HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int Dir;
    //P1
    if(i%2!=0){
    SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer1:");
    printf("\nEnter number of spaces: \n");}
    else {//P2
        SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer2:");
    printf("\nEnter direction: \n");}
    scanf("%i", &Dir);
    return Dir;
}

int UserEnterPengID(int i){
   HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int PID;
    //P1
    if(i%2!=0){
    SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer1:");
    printf("\nEnter number of penguin: \n");}
    else {//P2
        SetConsoleTextAttribute(hConsole, 14);
    printf("\nPlayer2:");
    printf("\nEnter number of spaces: \n");}
    scanf("%i", &PID);
    return PID;


}
