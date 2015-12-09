void UserEnterCrdX(int i)
{
    int x;
    if (i%2==0) printf("Player1\n");
    else printf("Player2\n");
    printf("Enter X cordinate of your %i penguin: \n", i);
    scanf("%i", x);
    return x;
}

void UserEnterCrdY(int i)
{
    int y;
    if (i%2==0) printf("Player1\n");
    else printf("Player2\n");
    printf("Enter Y cordinate of your %i penguin: \n", i);
    scanf("%i", y);
    return y;
}

void UserEnterDir(int i)
{
    int d;
    if (i%2==0) printf("Player1\n");
    else printf("Player2\n");
    printf("Enter direction of movement according to %i penguin: \n", i);
    scanf("%i", d);
    return d;
}
