void inputElements1();
void integerInput();
int intSearch1(int e[], int target, int l, int r);
void generateElements();
void binaryDescription();


void binary()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sBinary Search %s----\n", GRN, RESET);
        printf("[1] Input Elements\n");
        printf("[2] Generate Elements\n");
        printf("[3] Description\n");
        printf("[4] Exit\n");
        printf("----------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sBinary Search%s ----\n", GRN, RESET);
            printf("[1] Input Elements\n");
            printf("[2] Generate Elements\n");
            printf("[3] Description\n");
            printf("[4] Exit\n");
            printf("----------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                inputElements1();
                break;

            case 2:
                generateElements();
                break;

            case 3:
                binaryDescription();
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


void inputElements1()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("----%sBinary Search Input%s----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Exit\n");
        printf("----------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sBinary Search Input%s ----\n", GRN, RESET);
            printf("[1] Integers\n");
            printf("[2] Exit\n");
            printf("----------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                integerInput();
                break;

            case 2:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                getchar();
                break;
        }
    }
}


void integerInput()
{
    clearScreen();
    int array_size, target;

    printf("---- %sBinary Search Integer%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input. Please enter an integer%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int e[array_size];

    printf("Enter %d elements:\n", array_size);
    for(int i = 0; i < array_size; i++)
    {
        while(scanf("%d", &e[i]) != 1)
        {
            printf("%sInvalid Input. Please enter an integer%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            printf("Enter %d elements:\n", array_size);
        }
    }

    printf("Enter target element: ");
    while(scanf("%d", &target) != 1)
    {
        printf("%sInvalid Input. Please enter an integer%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        printf("Enter target element: ");
    }

    bSort(e, array_size);
    int l = 0, r = array_size - 1;
    int index = intSearch1(e, target, l, r);


    clearScreen();
    printf("------------- %sSearching%s ------------\n", GRN, RESET);
    for(int i = 0; i < array_size; i++)
        printf("%d ", e[i]);

    printf("\nTarget: %d\n", target);
    if(index == -1)
        printf("Target NOT found!\n");
    else
        printf("Target found!\n");
    printf("Index: %d\n", index);
    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    getchar();
    getchar();
}


int intSearch1(int e[], int target, int l, int r)
{
    if(l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if(e[mid] == target)
        return mid;
    else if(e[mid] > target)
        return intSearch1(e, target, l, mid - 1);
    else
        return intSearch1(e, target, mid + 1, r);
}


void generateElements()
{
    clearScreen();
    int array_size, target;

    printf("---- %sBinary Search Generated Elements%s ----\n", GRN, RESET);
    printf("Enter number of elements: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input. Please enter an integer%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    // changed it to dynamic array
    int *e = malloc(array_size * sizeof(int));
    if(e == NULL)
    {
        printf("%sMemory allocation failed.%s\n", RED, RESET);
        getchar();
        return;
    }
    generate(array_size, e);

    printf("Enter target element: ");
    while(scanf("%d", &target) != 1)
    {
        printf("%sInvalid Input. Please enter an integer%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int l = 1, r = array_size - 1;
    int index = intSearch1(e, target, l, r);

    clearScreen();
    printf("------------- %sSearching%s ------------\n", GRN, RESET);
    for(int i = 0; i < array_size; i++)
        printf("%d ", e[i]);

    printf("\nTarget: %d\n", target);
    if(index == -1)
        printf("Target NOT found!\n");
    else
        printf("Target found!\n");
    printf("Index: %d\n", index);
    printf("Time Complexity: O(log n)\n");
    printf("Space Complexity: O(1)\n");

    getchar();
    getchar();
}


void binaryDescription()
{
    clearScreen();
    printf("----------------- %sDescription%s -------------------\n", GRN, RESET);
    printf("Binary search is an efficient algorithm that\n");
    printf("finds the position of a target value within\n");
    printf("a sorted array by repeatedly dividing the\n");
    printf("search range in half. It compares the target\n"); 
    printf("to the middle element and eliminates half the\n");
    printf("elements based on the comparison, achieving a\n");
    printf("time complexity of O(log n).\n");

    getchar();
}