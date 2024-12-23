void insertArray()
{
    clearScreen();
    int arr_size;
    int x, pos;

    printf("------ %sInsert Element%s ------\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &arr_size) != 1 || arr_size <= 0)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int e[arr_size + 1];

    printf("Enter %d elements:\n", arr_size);
    for(int i = 0; i < arr_size; i++)
    {
        while(scanf("%d", &e[i]) != 1)
        {
            printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            return;
        }
    }

    printf("\nEnter element to insert: ");
    while(scanf("%d", &x) != 1)
    {
        printf("Invalid Input!\n");
        while(getchar() != '\n');
        getchar();
        return;
    }

    printf("Enter index (0-based) to insert the element: ");
    while (scanf("%d", &pos) != 1 || pos < 0 || pos > arr_size) {
        printf("%sInvalid position! Enter a value between 0 and %d.%s\n", RED, arr_size, RESET);
        while (getchar() != '\n'); 
        getchar();
        return;
    }

    for(int i = arr_size; i > pos; i--)
        e[i] = e[i - 1];

    e[pos] = x;

    for(int i = 0; i <= arr_size; i++)
        printf("%d ", e[i]);

    getchar();
    getchar();
}