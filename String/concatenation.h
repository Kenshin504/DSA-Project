void concatenation()
{
    clearScreen();
    
    char str1[100];
    char str2[100];

    printf("---- %sString Concatenation%s ----\n", GRN, RESET);
    printf("Enter string one: ");
    scanf("%s", str1);
    while(getchar() != '\n');

    printf("Enter string two: ");
    scanf("%s", str2);
    while(getchar() != '\n');

    strcat(str1, str2);

    clearScreen();
    printf("---- %sConcatenation Complete%s ----\n", GRN, RESET);
    printf("%s", str1);

    getchar();
}