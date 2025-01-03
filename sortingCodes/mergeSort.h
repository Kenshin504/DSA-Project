void mIntegerInput();
void mSort(int e[], int left, int right);
void merge(int e[], int left, int mid, int right);
void mDisplayResult(int e[], int size);
void mergeDesc();


void mergeSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sMerge Sort%s ----\n", GRN, RESET);
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
                mIntegerInput();
                break;

            case 2:
                mergeDesc();
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


void mIntegerInput()
{
    clearScreen();
    int array_size;

    printf("---- %sMerge Sort Integers%s ----\n", GRN, RESET);
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
    
    mSort(e, 0, array_size - 1);
    mDisplayResult(e, array_size);
}


void mSort(int e[], int left, int right)
{
    // Base case: if the sub-array has less than two elements, it is already sorted
    if(left < right)
    {
        // Find the middle point of the current sub-array
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        mSort(e, left, mid);
        mSort(e, mid + 1, right);

        // Merge the sorted halves
        merge(e, left, mid, right);
    }
}


void merge(int e[], int left, int mid, int right)
{
    int i, j, k;
    // Sizes of the two sub-arrays to merge
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the two halves
    int L[n1], R[n2];

    // Copy data to the temporary arrays L[] and R[]
    for(i = 0; i < n1; i++)
        L[i] = e[left + i];
    for(j = 0; j < n2; j++)
        R[j] = e[mid + 1 + j];

    // Initial indices of the sub-arrays and merged array
    i = 0; 
    j = 0;
    k = left;

    // Merge the temporary arrays back into the original array
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            e[k] = L[i];
            i++;
        }
        else 
        {
            e[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while(i < n1)
    {
        e[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while(j < n2)
    {
        e[k] = R[j];
        j++;
        k++;
    }
}


void mDisplayResult(int e[], int size)
{
    clearScreen();
    printf("------------------- %sSorted Arrays%s --------------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(n)");

    getchar();
    getchar();
}

void mergeDesc()
{
    clearScreen();
    printf("------------------------ %sDescription%s --------------------------\n", GRN, RESET);
    printf("Merge Sort is a divide-and-conquer algorithm that recursively\n"); 
    printf("splits an array into halves, sorts each half, and then merges \n");
    printf("them back into a sorted array.");

    getchar();
}