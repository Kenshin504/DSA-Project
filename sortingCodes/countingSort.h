void cIntegerInput();
void cSort(int e[], int size);
void countingDesc();


void countingSort()
{
        int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sCounting Sort%s ----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Description\n");
        printf("[3] Exit\n");
        printf("-----------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        switch(ch)
        {
            case 1:
                cIntegerInput();
                break;

            case 2:
                countingDesc();
                getchar();
                break;

            case 3:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                getchar();
                break;
        }
    }
}


void cIntegerInput()
{
    clearScreen();
    int array_size;

    printf("---- %sCounting Sort Integers%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int e[array_size];
    
    printf("Enter %d Elements to Sort:\n", array_size);
    for(int i = 0; i < array_size; i++)
    {
        while(scanf("%d", &e[i]) != 1)
        {
            printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            return;
        }
    }

    cSort(e, array_size);
}


void cSort(int e[], int size)
{
    int output[size];
    int max = e[0];

    for(int i = 1; i < size; i++)
        if(e[i] > max)
            max = e[i];

    int countArray[max + 1];
    for(int i = 0; i <= max; i++)
        countArray[i] = 0;

    for(int i = 0; i < size; i++)
        countArray[e[i]]++;

    for(int i = 1; i <= max; i++)
        countArray[i] += countArray[i - 1];

    for(int i = size - 1; i >= 0; i--)
    {
        output[countArray[e[i]] - 1] = e[i];
        countArray[e[i]]--;
    }

    for(int i = 0; i < size; i++)
        e[i] = output[i];


    clearScreen();
    printf("----------------- %sSorted Arrays%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Time Complexity: O(n + m)\n");
    printf("Space Complexity: O(k + n)\n");
    
    getchar();
    getchar();
}


void countingDesc()
{
    clearScreen();
    printf("--------------------- %sDescription%s ----------------------------\n", GRN, RESET);
    printf("Counting Sort is a non-comparative sorting algorithm that\n"); 
    printf("works by counting the occurrences of each element in the\n");
    printf("input array. It then uses these counts to place the elements\n");
    printf("in their correct positions in the sorted output array.\n");
    printf("The algorithm is efficient for sorting integers or\n");
    printf("categorical data with a known, limited range of values. \n");
    printf("Its time complexity is O(n + k), where n is the number of\n");
    printf("elements and k is the range of the input values.");

    getchar();
}