void characterAccess()
{
    clearScreen();
    
    char str[100];
    int index; 

    printf("---- %sCharacter Access%s ----\n", GRN, RESET);
    printf("Enter string: ");
    scanf("%s", str);
    while(getchar() != '\n');

    printf("Enter index number: ");
    while(scanf("%d", &index) != 1 || index <= -1)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    if(strlen(str) < index) 
    {
        printf("%sInvalid index. Out of Bounds!%s\n", RED, RESET);
        getchar();
        getchar();
        return;
    }

    printf("\n\n---- %sResult%s ----\n", GRN, RESET);
    printf("Character: %c\n", str[index]);

    getchar();
    getchar();
}