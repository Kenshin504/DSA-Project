void insert()
{
    clearScreen();
    char str1[100];
    char str2[100];
    int index;

    printf("------- %sString Insertion%s --------\n", GRN, RESET);
    printf("Enter String for string 1: ");
    scanf("%s", str1);
    while(getchar() != '\n');

    printf("Enter String to insert: ");
    scanf("%s", str2);
    while(getchar() != '\n');

    printf("Enter number of index to insert: ");
    scanf("%d", &index);
    while(getchar() != '\n');

    if (index < 0 || index > strlen(str1))
    {
        printf("%sInvalid index!%s\n", RED, RESET);
        getchar();
        return;
    }

    int size1 = strlen(str1);
    int size2 = strlen(str2);

    for(int i = size1; i >= index; i--)
        str1[i + size2] = str1[i];

    for(int i = 0; i < size2; i++)
        str1[index + i] = str2[i];

    printf("\n\n---- %sString Insertion Complete%s ----\n", GRN, RESET);
    printf("%s\n", str1);


    getchar();
}