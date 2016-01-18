#include "main.h"

int main() {

    Intro();

    Pointer PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2;
    int menu, p, i = 0;
    for(;;) {
        printf("What do you want to do? ");
        printf("\n1. Start the game ");
        printf("\n2. Show instructions ");
        printf("\n3. Exit game \n");

        scanf("%d", &menu);
        //choosing Player1 algorithm
        switch(menu) {
            case 1: {
                printf("Set game parameters now!");

                while(i == 0) {
                    Sleep(700);
                    system ( "cls" );
                    printf("Choose Player1's algorithm:\n");
                    printf("1. Manual Override\n");
                    printf("2. Dummy\n");
                    printf("3. Center\n");
                    printf("4. Julian Tian's algorithm\n");
                    printf("112. Bator\n");

                    scanf("%i", &p);
                    switch(p) {
                        case 1: {
                            printf("You chose Manual Override as Player1's algorithm!\n");
                            PointerX1 = &UserEnterCrdX;
                            PointerY1 = &UserEnterCrdY;
                            PointerDir1 = &UserEnterDir;
                            PointerSpaces1 = &UserEnterNumOfSpaces;
                            PointerPengID1 = &UserEnterPengID;
                            i = 1;
                            break;
                        }
                        case 2: {
                            printf("You chose Dummy as Player1's algorithm!\n");
                            PointerX1 = &DummyCrdX;
                            PointerY1 = &DummyCrdY;
                            PointerDir1 = &DummyDir;
                            PointerSpaces1 = &DummySpaces;
                            PointerPengID1 = &DummyPengID;
                            i = 1;
                            break;
                        }
                        case 3: {
                            printf("You chose Center as Player1's algorithm!\n");
                            PointerX1 = &CenterCrdX;
                            PointerY1 = &CenterCrdY;
                            PointerDir1 = &CenterDir;
                            PointerSpaces1 = &CenterSpaces;
                            PointerPengID1 = &CenterPengID;
                            i = 1;
                            break;
                        }
                        case 4: {
                            printf("You chose Julian Tian's algorithm as Player1's algorithm!\n");
                            PointerX1 = &JulianCrdX;
                            PointerY1 = &JulianCrdY;
                            PointerDir1 = &JulianDir;
                            PointerSpaces1 = &JulianSpaces;
                            PointerPengID1 = &JulianPengID;
                            i = 1;
                            break;
                        }
                        case 112: {
                            printf("Bator");
                            PointerX1 = &NightmareCrdX;
                            PointerY1 = &NightmareCrdY;
                            PointerDir1 = &DummyDir;
                            PointerSpaces1 = &DummySpaces;
                            PointerPengID1 = &DummyPengID;
                            i = 1;
                            break;
                        }
                        default: {
                            printf("Set a proper parameter!\n");
                            break;
                        }
                    }
                }

                i = 0;

                while(i == 0) {
                    Sleep(700);
                    system ( "cls" );
                    printf("Choose Player2's algorithm:\n");
                    printf("1. Manual Override\n");
                    printf("2. Dummy\n");
                    printf("3. Center\n");
                    printf("4. Julian Tian's algorithm\n");
                    printf("112. Bator\n");

                    scanf("%i", &p);
                    switch(p) {
                        case 1: {
                            printf("You chose Manual Override as Player2's algorithm!\n");
                            PointerX2 = &UserEnterCrdX;
                            PointerY2 = &UserEnterCrdY;
                            PointerDir2 = &UserEnterDir;
                            PointerSpaces2 = &UserEnterNumOfSpaces;
                            PointerPengID2 = &UserEnterPengID;
                            i = 1;
                            break;
                        }
                        case 2: {
                            printf("You chose Dummy as Player2's algorithm!\n");
                            PointerX2 = &DummyCrdX;
                            PointerY2 = &DummyCrdY;
                            PointerDir2 = &DummyDir;
                            PointerSpaces2 = &DummySpaces;
                            PointerPengID2 = &DummyPengID;
                            i = 1;
                            break;
                        }
                        case 3: {
                            printf("You chose Center as Player2's algorithm!\n");
                            PointerX2 = &CenterCrdX;
                            PointerY2 = &CenterCrdY;
                            PointerDir2 = &CenterDir;
                            PointerSpaces2 = &CenterSpaces;
                            PointerPengID2 = &CenterPengID;
                            i = 1;
                            break;
                        }
                        case 4: {
                            printf("You chose Julian Tian's algorithm as Player1's algorithm!\n");
                            PointerX2 = &JulianCrdX;
                            PointerY2 = &JulianCrdY;
                            PointerDir2 = &JulianDir;
                            PointerSpaces2 = &JulianSpaces;
                            PointerPengID2 = &JulianPengID;
                            i = 1;
                            break;
                        }
                        case 112: {
                            printf("Bator");
                            PointerX1 = &NightmareCrdX;
                            PointerY1 = &NightmareCrdY;
                            PointerDir1 = &DummyDir;
                            PointerSpaces1 = &DummySpaces;
                            PointerPengID1 = &DummyPengID;
                            i = 1;
                            break;
                        }
                        default: {
                            printf("Set a proper parameter!\n");
                            break;
                        }
                    }
                }
                Sleep(700);
                system ( "cls" );

                //run game
                PlayGame(PointerX1, PointerY1, PointerDir1, PointerSpaces1, PointerPengID1, PointerX2, PointerY2, PointerDir2, PointerSpaces2, PointerPengID2);
                break;
            }
            case 2: {
                break;
            }
            case 3: {
                printf("\nGoodbye!");
                exit(0);
            }
            default : {
                printf("Give a proper choice!\n");
                break;
            }
        }
    }
}


