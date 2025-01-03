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
    // Base case: If the sub-array has less than two elements, it is already sorted
    if(low < high)
    {
        // Partition the array and get the pivot index
        int pi = partition(e, low, high);

        // Recursively sort the elements before and after the pivot
        qSort(e, low, pi - 1);
        qSort(e, pi + 1, high);
    }
}


int partition(int e[], int low, int high)
{
    // Choose the last element as the pivot
    int pivot = e[high];   
    int i = low - 1; // Index of the smaller element

    // Rearrange elements based on the pivot
    for(int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than the pivot
        if(e[j] < pivot)
        {
            i++; // Increment the index of the smaller element
            swaps(&e[i], &e[j]); // Swap the current element with the element at index i
        }
    }

    // Place the pivot element in its correct position
    swaps(&e[i + 1], &e[high]);
    return i + 1;  // Return the partition index
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