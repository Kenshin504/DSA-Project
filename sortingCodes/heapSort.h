void hIntegerInput();
void hSort(int e[], int size);
void heapify(int e[], int size, int i);
void hDisplayResult(int e[], int size);
void heapDesc();


void heapSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sHeap Sort%s ----\n", GRN, RESET);
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
                hIntegerInput();
                break;

            case 2:
                heapDesc();
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


void hIntegerInput()
{
    clearScreen();
    int array_size;

    printf("---- %sHeap Sort Integers%s ----\n", GRN, RESET);
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

    hSort(e, array_size);
    hDisplayResult(e, array_size);
}


void hSort(int e[], int size)
{
    // Build the max heap from the input array
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(e, size, i);

    // Extract elements from the heap one by one
    for(int i = size - 1; i > 0; i--)
    {
        // Move the current root (largest element) to the end
        swaps(&e[0], &e[i]);    
        
        // Call heapify on the reduced heap to maintain the heap property
        heapify(e, i, 0);
    }
}


void heapify(int e[], int size, int i)
{
    // Initialize the largest element as root
    int largest = i;

    // Calculate the indices of the left and right children
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // Check if the left child exists and is greater than the root
    if(l < size && e[l] > e[largest])
        largest = l;

    // Check if the right child exists and is greater than the largest so far
    if(r < size && e[r] > e[largest])
        largest = r;

    // If the largest is not the root, swap and recursively heapify the affected sub-tree
    if(largest != i)
    {
        swaps(&e[i], &e[largest]);
        heapify(e, size, largest);
    }
}



void hDisplayResult(int e[], int size)
{
    clearScreen();
    printf("---------------------- %sSorted Arrays%s ----------------------------\n",GRN, RESET);
    displayIntegers(size, e);
    printf("Time Complexity: O(n log n)\n");
    printf("Space Complexity: O(1)\n");

    getchar();
    getchar();
}


void heapDesc()
{
    clearScreen();
    printf("----------------------------- %sDescription%s ----------------------------------\n", GRN, RESET);
    printf("A heap is a binary tree that maintains the heap property: in a max-heap,\n");
    printf("parents are ≥ children; in a min-heap, parents are ≤ children. It's\n");
    printf("used in sorting and priority queues.");

    getchar();
}