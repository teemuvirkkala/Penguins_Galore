#include "main.h"

void main() {

    Intro();

    PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2;
    int menu, p, P1ID = 0, P2ID = 0;
    printf("What do you want to do? ");
    printf("\n1. Start the game ");
    printf("\n2. Show instructions ");
    printf("\n3. Exit game \n");


    scanf("%d", &menu);
    //choosing Player1 algorithm
    switch(menu) {
        case 1: {
            printf("Set game parameters now!");

            while(P1ID == 0) {
                Sleep(1000);
                system ( "cls" );
                printf("Choose Player1's algorithm:\n");
                printf("1. Manual Override\n");
                printf("2. Dummy\n");

                scanf("%i", &p);
                switch(p) {
                    case 1: {
                        printf("You chose Manual Override as Player1's algorithm!\n");
                        P1ID = 1;
                        PointerX1 = &UserEnterCrdX;
                        PointerY1 = &UserEnterCrdY;
                        PointerDir1 = &UserEnterDir;
                        PointerSpaces1 = &UserEnterNumOfSpaces;
                        PointerPengID1 = &UserEnterPengID;
                        break;
                    }
                    case 2: {
                        printf("You chose Dummy as Player1's algorithm!\n");
                        P1ID = 2;
                        PointerX1 = &DummyCrdX;
                        PointerY1 = &DummyCrdY;
                        PointerDir1 = &UserEnterDir;
                        PointerSpaces1 = &UserEnterNumOfSpaces;
                        PointerPengID1 = &UserEnterPengID;
                        break;
                    }
                    default: {
                        printf("Set a proper parameter!\n");
                        break;
                    }
                }
            }

            while(P2ID == 0) {
                Sleep(1000);
                system ( "cls" );
                printf("Choose Player2's algorithm:\n");
                printf("1. Manual Override\n");
                printf("2. Dummy\n");

                scanf("%i", &p);
                switch(p) {
                    case 1: {
                        printf("You chose Manual Override as Player2's algorithm!\n");
                        P2ID = 1;
                        PointerX2 = &UserEnterCrdX;
                        PointerY2 = &UserEnterCrdY;
                        PointerDir2 = &UserEnterDir;
                        PointerSpaces2 = &UserEnterNumOfSpaces;
                        PointerPengID2 = &UserEnterPengID;
                        break;
                    }
                    case 2: {
                        printf("You chose Dummy as Player1's algorithm!\n");
                        P2ID = 2;
                        PointerX2 = &DummyCrdX;
                        PointerY2 = &DummyCrdY;
                        PointerDir2 = &UserEnterDir;
                        PointerSpaces2 = &UserEnterNumOfSpaces;
                        PointerPengID2 = &UserEnterPengID;
                        break;
                    }
                    default: {
                        printf("Set a proper parameter!\n");
                        break;
                    }
                }
            }
            Sleep(1000);
            system ( "cls" );

            //run game
            PlayGame(P1ID, PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, P2ID, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2);
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            printf("\nGoodbye!");
            break;
        }
    }
}

