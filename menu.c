#include "main.h"

void main(){

    Intro();



Pointer PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2;
    int menu,p;
    printf("What do you want to do? ");
    printf("\n1. Start the game ");
    printf("\n2. Show instructions ");
    printf("\n3. Exit game \n");


    scanf("%d", &menu);
    //choosing Player1 algorithm
        switch(menu){
            case 1: {
                printf("Set game parameters now!");
                Sleep(1000);
                system ( "cls" );
                printf("Choose Player1's algorithm:\n");
                printf("1. Manual Override\n");

                scanf("%i", &p);
                switch(p){
                    case 1: {
                        printf("You chose Manual Override as Player1's algorithm!\n");
            PointerX1 = &UserEnterCrdX;
            PointerY1 = &UserEnterCrdY;
            PointerDir1 = &UserEnterDir;
            PointerSpaces1 = &UserEnterNumOfSpaces;
            PointerPengID1 = &UserEnterPengID;
            Sleep(1000);
            system ( "cls" );
            break;}
            //case2
                }

            printf("Choose Player2's algorithm:\n");
                printf("1. Manual Override\n");

                scanf("%i", &p);
                switch(p){
                    case 1: {
                        printf("You chose Manual Override as Player2's algorithm!\n");
            PointerX2 = &UserEnterCrdX;
            PointerY2 = &UserEnterCrdY;
            PointerDir2 = &UserEnterDir;
            PointerSpaces2 = &UserEnterNumOfSpaces;
            PointerPengID2 = &UserEnterPengID;
            break;}
            //case2
                }
                //run game
            PlayGame(PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2);
            break;}
                case 2: {
                break;
                }
                case 3: {
                printf("\nGoodbye!");
                break;}
            }
}

