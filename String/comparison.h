void compare(char str1[], char str2[]);
void lowercase(char str[]);


void comparison()
{
    clearScreen();

    char str1[100];
    char str2[100];

    printf("---- %sString Comparison%s ----\n", GRN, RESET);
    printf("Enter String 1: ");
    scanf("%s", str1);
    while(getchar() != '\n');
    lowercase(str1);

    printf("Enter String 2: ");
    scanf("%s", str2);
    while(getchar() != '\n');
    lowercase(str2);

    compare(str1, str2);


    getchar();
}


void compare(char str1[], char str2[])
{
    int x = strcmp(str1, str2);

    printf("\n\n---- %sResult%s ----\n", GRN, RESET);

    if(x != 0)
    {
        printf("%s is not equal to %s\n", str1, str2);

        if(x > 0)
            printf("%s is greater than %s\n", str1, str2);
        else
            printf("%s is greater than %s\n", str2, str1);
    }
    else 
        printf("%s is equal to %s\n", str1, str2);
}


void lowercase(char str[])
{
    for(int i = 0; i < strlen(str); i++)
        str[i] = tolower(str[i]);
}