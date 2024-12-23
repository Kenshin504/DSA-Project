void qIntegerInput();
void qSort(int e[], int left, int right);
int partition(int e[], int left, int right);
void qDisplayResult(int e[], int size);
void quickDesc();


void quickSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sQuick Sort%s ----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Description\n");
        printf("[3] Exit\n");
        printf("-------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        switch(ch)
        {
            case 1:
                qIntegerInput();
                break;

            case 2:
                quickDesc();
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


void qIntegerInput()
{
    clearScreen();
    int array_size;

    printf("---- %sQuick Sort Integers%s ----\n", GRN, RESET);
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

    qSort(e, 0, array_size - 1);
    qDisplayResult(e, array_size);
}


void qSort(int e[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(e, low, high);

        qSort(e, low, pi - 1);
        qSort(e, pi + 1, high);
    }
}


int partition(int e[], int low, int high)
{
    int pivot = e[high];   
    int i = low - 1;

    for(int j = low; j <= high - 1; j++)
    {
        if(e[j] < pivot)
        {
            i++;
            swaps(&e[i], &e[j]);
        }
    }

    swaps(&e[i + 1], &e[high]);
    return i + 1;  
}


void qDisplayResult(int e[], int size)
{
    clearScreen();
    printf("------------------ %sSorted-Arrays%s ---------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(n)");

    getchar();
    getchar();
}


void quickDesc()
{
    clearScreen();
    printf("--------------------------- %sDescription%s -------------------------------\n", GRN, RESET);
    printf("Quick Sort is a divide-and-conquer algorithm that selects a pivot,\n"); 
    printf("partitions the array around the pivot, and recursively sorts the\n"); 
    printf("partitions.");

    getchar();
}