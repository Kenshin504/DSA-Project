void getString(char str[], int pos, int len);


void substring()
{
    clearScreen();

    char str[100];
    int pos, len;

    printf("---- %sSubstring%s ----\n", GRN, RESET);
    printf("Enter String: ");
    scanf(" %99[^\n]", str);
    while(getchar() != '\n');


    printf("Enter starting position: ");
    while(scanf("%d", &pos) != 1 || pos <= -1)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    if (strlen(str) < pos)
    {
        printf("%sIndex Out of Bounds!%s", RED, RESET);
        clearBuffer();
        getchar();
        return;
    }

    printf("Enter length: ");
    while(scanf("%d", &len) != 1 || len <= -1)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    getString(str, pos, len);

    getchar();
    getchar();
}


void getString(char str[], int pos, int len)
{
    int i = 0;
    char subString[100];

    while(i < len)
    {
        subString[i] = str[pos + i - 1];
        i++;
    }

    subString[i] = '\0';

    printf("\n\n------- %sResult%s ------\n", GRN, RESET);
    printf("Substring: %s\n", subString);
}