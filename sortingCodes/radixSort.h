void rIntegerInput();
void rSort(int e[], int size);
int getMax(int e[], int size);
void countSort(int e[], int size, int exp);
void rDisplayResult(int e[], int size);
void radixDesc();


void radixSort()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sRadix Sort%s ----\n", GRN, RESET);
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
                rIntegerInput();
                break;

            case 2:
                radixDesc();
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


void rIntegerInput()
{
    clearScreen();
    int array_size;

    printf("---- %sRadix Sort Integers%s ----\n", GRN, RESET);
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

    rSort(e, array_size);
    rDisplayResult(e, array_size);
}


void rSort(int e[], int size)
{
    int m = getMax(e, size);

    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(e, size, exp);
}


int getMax(int e[], int size)
{
    int mx = e[0];
    for(int i = 1; i < size; i++)
        if(e[i] > mx)
            mx = e[i];
    return mx;
}


void countSort(int e[], int size, int exp)
{
    int output[size];
    int count[10] = {0};

    for(int i = 0; i < size; i++)
        count[(e[i] / exp) % 10]++;

    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(int i = size - 1; i >= 0; i--)
    {
        output[count[(e[i] / exp) % 10] - 1] = e[i];
        count[(e[i] / exp) % 10]--;
    }

    for(int i = 0; i < size; i++)
        e[i] = output[i];
}


void rDisplayResult(int e[], int size)
{
    clearScreen();
    printf("------------------------ %sSorted-Arrays%s ----------------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Time Complexity: O(d *(n + b))\n");
    printf("Space Complexity: O(n + k)");

    getchar();
    getchar();
}


void radixDesc()
{
    clearScreen();
    printf("------------------------------ %sDescription%s ------------------------------\n", GRN, RESET);
    printf("Radix Sort is a non-comparative sorting algorithm that sorts numbers\n");
    printf("digit by digit, starting from the least significant digit to the most\n"); 
    printf("significant, using a stable sorting method like counting sort at each\n");
    printf("step.");

    getchar();
}