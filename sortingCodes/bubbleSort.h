void bSIntegerInput();
void bSSort(int e[], int size, int *cmp, int *swp);
void bSCharacterInput();
void bSCharSort(char e[], int size, int *cmp, int *swp);
void bubbleDesc();


void bubbleSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sBubble Sort%s ----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Characters\n");
        printf("[3] Description\n");
        printf("[4] Exit\n");
        printf("--------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        switch(ch)
        {
            case 1:
                bSIntegerInput();
                break;

            case 2:
                bSCharacterInput();
                break;

            case 3:
                bubbleDesc();
                getchar();
                break;

            case 4:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                while(getchar() != '\n');
                break;
        }
    }
}


void bSIntegerInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;

    printf("---- %sBubble Sort Integers%s ----\n", GRN, RESET);
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

    bSSort(e, array_size, &comparison, &swaps);
}


void bSSort(int e[], int size, int *cmp, int *swp)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            (*cmp)++;
            if(e[j] > e[j + 1])
            {
                swaps(&e[j], &e[j+1]);
                (*swp)++;
            }
        }
    }

    clearScreen();
    printf("---------------------- %sSorted Integers%s --------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Comparison: %d\n", *cmp);
    printf("Swaps: %d\n", *swp);
    if(*swp == 0)
        printf("Time Complexity: O(n)\n");
    else
        printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");
    
    getchar();
    getchar();
}


void bSCharacterInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;
    
    printf("---- %sBubble Sort Characters%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input! Please enter an integer%s.\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    char e[array_size];

    printf("Enter %d Elements to Sort:\n", array_size);
    for(int i = 0; i < array_size; i++)
    {
        while(1)
        {
            printf("Element %d: ", i + 1);
            while(getchar() != '\n');
            if(scanf("%c", &e[i]) == 1 && isalpha(e[i]))
                break;

            getchar();
            printf("%sInvalid Input. Please enter a character%s", RED, RESET);
            getchar();
            return;
        }
    }

    for(int i = 0; i < array_size; i++)
        e[i] = toupper(e[i]);

    bSCharSort(e, array_size, &comparison, &swaps);
}


void bSCharSort(char e[], int size, int *cmp, int *swp)
{
    for(int i = 0; i < size - 1; i++) 
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            (*cmp)++;
            if(e[j] > e[j + 1])
            {
                charSwaps(&e[j], &e[j + 1]);
                (*swp)++;
            }  
        }
    }

    clearScreen();
    printf("---------------------- %sSorted-Characters%s --------------------\n", GRN, RESET);
    displayCharacters(e, size);
    printf("Comparison: %d\n", *cmp);
    printf("Swaps: %d\n", *swp);
    if(*swp == 0)
        printf("Time Complexity: O(n)\n");
    else
        printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");
    
    getchar();
    getchar();
}


void bubbleDesc()
{
    clearScreen();
    printf("------------------------- %sDescription%s -----------------------\n", GRN, RESET);
    printf("Bubble Sort is a simple sorting algorithm that repeatedly\n");
    printf("compares adjacent elements in an array, swapping them if\n");
    printf("they are in the wrong order. This process continues until\n"); 
    printf("the array is sorted, with larger elements \"bubbling\" to\n");
    printf("the end in each pass. Its time complexity is O(n2) for\n"); 
    printf("worst and average cases, and O(n)for the best case\n");
    printf("(when the array is already sorted).");

    getchar();
}