void inputElements();
void integersInput();
void intSearch(int e[], int size, int target);
void charactersInput();
void charSearch(char e[], int size, char target);
void linearDescription();


void linear()
{
    int ch; 
    while(1)
    {
        clearScreen();
        printf("---- %sLinear Search%s ----\n", GRN, RESET);
        printf("[1] Input Elements\n");
        printf("[2] Description\n");
        printf("[3] Exit\n");
        printf("----------------------\n");
        printf("Response: ");    
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sLinear Search%s ----\n", GRN, RESET);
            printf("[1] Input Elements\n");
            printf("[2] Description\n");
            printf("[3] Exit\n");
            printf("----------------------\n");
            printf("Response: ");  
        }

        switch(ch)
        {
            case 1:
                inputElements();
                break;

            case 2:
                linearDescription();
                getchar();
                break;

            case 3:
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


void inputElements()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("----- %sLinear Search Input%s -----\n", GRN, RESET);
        printf("[1] Integers\n");
        printf("[2] Characters\n");
        printf("[3] Exit\n");
        printf("-----------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("----- %sLinear Search Input%s -----\n", GRN, RESET);
            printf("[1] Integers\n");
            printf("[2] Characters\n");
            printf("[3] Exit\n");
            printf("-----------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                integersInput();
                break;

            case 2:
                charactersInput();
                break;

            case 3:
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


void integersInput()
{
    clearScreen();
    int array_size, target;

    printf("---- %sLinear Search Integer%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input. Please enter an integer!%s\n", RED, RESET);
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
            printf("%sInvalid Input. Please enter an integer!%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            return;
        }
    }

    printf("Enter target element: ");
    while(scanf("%d", &target) != 1)
    {
        printf("%sInvalid Input. Please enter an integer!%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    intSearch(e, array_size, target);
    getchar();
}


void intSearch(int e[], int size, int target)
{
    clearScreen();
    int index; 
    int flag = 0; 

    printf("-------- %sSearching%s --------\n", GRN, RESET);
    for(int i = 0; i < size; i++)
    {
        if(target == e[i])
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if(!flag)
    {
        printf("Element was NOT found!");
        getchar();
        return;
    }

    displayIntegers(size, e);
    printf("Target: %d\n", target);
    printf("Element found!\n");
    printf("Index: %d\n", index);
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(1)\n");
    getchar();
}


void charactersInput()
{
    clearScreen();
    int array_size;
    char target;

    printf("---- %sLinear Search Characters%s ----\n", GRN, RESET);
    printf("Enter size of an array: ");
    while(scanf("%d", &array_size) != 1 || array_size <= 0)
    {
        printf("%sInvalid Input. Please enter an integer!%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    char e[array_size];
    
    printf("Enter %d elements:\n", array_size);
    for(int i = 0; i < array_size; i++) 
    {
        printf("Element %d: ", i + 1);
        while(1) 
        {
            while(getchar() != '\n');
            if(scanf("%c", &e[i]) == 1 && isalpha(e[i]))
                break;

            getchar();
            printf("%sInvalid Input. Please enter a character!%s\n", RED, RESET);
            getchar();
            return;
        }
    }

    printf("Enter target element: ");
    while(1)
    {
        while(getchar() != '\n');
        if(scanf("%c", &target) == 1 && isalpha(target))
            break;

        getchar();
        printf("%sInvalid Input. Please enter a character!\n%s", RED, RESET);
        getchar();
        return;
    }

    charSearch(e, array_size, target);
    getchar();
}


void charSearch(char e[], int size, char target)
{
    clearScreen();
    int index; 
    int flag = 0; 

    printf("-------- %sSearching%s --------\n", GRN, RESET);
    for(int i = 0; i < size; i++)
    {
        if(target == e[i])
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if(!flag)
    {
        printf("Element was NOT found!");
        getchar();
        return;
    }

    for(int i = 0; i < size; i++)
        printf("%c ", e[i]);
    printf("\nTarget: %c\n", target);
    printf("Element found!\n");
    printf("Index: %d\n", index);
    printf("Time Complexity: O(n)\n");
    printf("Space Complexity: O(1)\n");
    getchar();
}


void linearDescription()
{
    clearScreen();
    printf("--------------------- %sDescription%s --------------------\n", GRN, RESET);
    printf("Linear search is a simple searching algorithm that\n");
    printf("checks each element in a list one by one until the\n"); 
    printf("desired element is found or the end of the list is\n");
    printf("reached. It works well for small datasets but is\n");
    printf("less efficient for large datasets due to its O(n)\n");
    printf("time complexity.");
    getchar();
}