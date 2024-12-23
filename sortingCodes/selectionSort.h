void sIntegerInput();
void sSort(int e[], int size, int *cmp, int *swp);
void sCharacterInput();
void sCharSort(char e[], int size, int *cmp, int *swp);
void selectionDesc();


void selectionSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sSelection Sort%s ----\n", GRN, RESET);
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
                sIntegerInput();
                break;

            case 2:
                sCharacterInput();
                break;

            case 3:
                selectionDesc();
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


void sIntegerInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;

    printf("---- %sSelection Sort Integers%s ----\n", GRN, RESET);
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
    
    sSort(e, array_size, &comparison, &swaps);
}


void sSort(int e[], int size, int *cmp, int *swp)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i; 

        for(int j = i + 1; j < size; j++)
        {
            (*cmp)++;
            if(e[j] < e[min])
                min = j;
        }

        swaps(&e[i], &e[min]);
        (*swp)++;
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


void sCharacterInput()
{
    clearScreen();
    int array_size;
    int comparison = 0, swaps = 0;
    
    printf("---- %sSelection Sort Characters%s ----\n", GRN, RESET);
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
            printf("%sInvalid Input. Please enter a character%s\n", RED, RESET);
            getchar();
            return;
        }
    }

    for(int i = 0; i < array_size; i++)
        e[i] = toupper(e[i]);

    sCharSort(e, array_size, &comparison, &swaps);
}  


void sCharSort(char e[], int size, int *cmp, int *swp)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i;

        for(int j = 1 + 1; j < size; j++)
        {
            (*cmp)++;
            if(e[j] < e[min])
                min = j;
        }

        charSwaps(&e[i], &e[min]);
        (*swp)++;
    }

    clearScreen();
    printf("----------------- %sSorted-Arrays%s -------------------\n", GRN, RESET);
    displayCharacters(e, size);
    printf("Comparison: %d\n", *cmp);
    printf("Swaps: %d\n", *swp);
    printf("Time Complexity: O(n^2)\n");
    printf("Space Complexity: O(1)\n");
    
    getchar();
    getchar();
}


void selectionDesc()
{
    clearScreen();
    printf("----------------------- %sDescription%s ------------------------------\n", GRN, RESET);
    printf("Selection Sort is a simple sorting algorithm that divides the\n"); 
    printf("array into a sorted and an unsorted part. It repeatedly selects\n"); 
    printf("the smallest (or largest) element from the unsorted part and\n"); 
    printf("swaps it with the first element of the unsorted part, gradually\n");
    printf("expanding the sorted section.");

    getchar();
}