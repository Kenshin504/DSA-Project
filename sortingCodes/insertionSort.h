void iIntegerInput();
void iSort(int e[], int size, int *cmp, int *swp);
void iCharacterInput();
void iCharSort(char e[], int size, int *cmp, int *swp);
void insertionDesc();


void insertionSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sInsertion Sort%s ----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Characters\n");
        printf("[3] Description\n");
        printf("[4] Exit\n");
        printf("-----------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        switch(ch)
        {
            case 1:
                iIntegerInput();
                break;

            case 2:
                iCharacterInput();
                break;

            case 3:
                insertionDesc();
                getchar();
                break;

            case 4:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                getchar();
                break;
        }
    }
}


void iIntegerInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;

    printf("---- %sInsertion Sort Integers%s ----\n", GRN, RESET);
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

    iSort(e, array_size, &comparison, &swaps);
}


void iSort(int e[], int size, int *cmp, int *swp)
{
    for(int i = 1; i < size; i++)
    {
        int key = e[i];
        int j = i - 1;

        while(j >= 0 && e[j] > key)
        {
            (*cmp)++;
            e[j + 1] = e[j];
            j -= 1;
            (*swp)++;
        }
         
        e[j + 1] = key;

        if(j >= 0)
            (*cmp)++;
    }

    clearScreen();
    printf("----------------- %sSorted Arrays%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Comparison: %d\n", *cmp);
    printf("Swaps: %d\n", *swp);
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");
    
    getchar();
    getchar();
}


void iCharacterInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;
    
    printf("---- %sSelection Sort Character%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
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

    iCharSort(e, array_size, &comparison, &swaps);
}


void iCharSort(char e[], int size, int *cmp, int *swp)
{
    for(int i = 1; i < size; i++)
    {
        int key = e[i];
        int j = i - 1;

        while(j >= 0 && e[j] > key)
        {
            (*cmp)++;
            e[j + 1] = e[j];
            j -= 1;
            (*swp)++;
        }
         
        e[j + 1] = key;

        if(j >= 0)
            (*cmp)++;
    }

    clearScreen();
    printf("----------------- %sSorted Arrays%s -------------------\n", GRN, RESET);
    displayCharacters(e, size);
    printf("Comparison: %d\n", *cmp);
    printf("Swaps: %d\n", *swp);
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");
    
    getchar();
    getchar();
}


void insertionDesc()
{
    clearScreen();
    printf("--------------------------- %sDescription%s -----------------------\n", GRN, RESET);
    printf("Insertion Sort is a simple sorting algorithm that builds\n"); 
    printf("the sorted array one element at a time. It repeatedly takes\n");
    printf("an element from the unsorted part and inserts it into its\n");
    printf("correct position in the sorted part by shifting larger\n");
    printf("elements to the right.");

    getchar();
}