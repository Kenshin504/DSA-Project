void length()
{
    clearScreen();

    char str[100];
    int length;

    printf("---- %sString Length%s ----\n", GRN, RESET);
    printf("Enter String: ");
    scanf(" %99[^\n]", str);
    while(getchar() != '\n');

    length = strlen(str);
    printf("String length: %d\n", length - 1);

    getchar();
}