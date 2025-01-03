#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H
bool intLSearch(int size, int *e, int k, int *index);

void linearSearch(int size, int *e)
{
    clearScreen();
    int num, index = 0; 
    
    printf("-------------- %sLinear Search%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Enter element to find: "); 
    while(scanf("%d", &num) != 1)
    {
        printf("%sInvalid Input!%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("-------------- %sLinear Search%s -------------------\n", GRN, RESET);
        displayIntegers(size, e);
        printf("Enter element to find: "); 
    }

    clearScreen();
    printf("-------------- %sLinear Search%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    if(intLSearch(size, e, num, &index))
    {
        printf("%sTarget Found!%s\n", GRN, RESET);
        printf("Target: %d\n", num);
        printf("Index: %d\n", index);
        printf("Time Complexity: O(n)\n");
        printf("Space Complexity: O(1)\n");
    }
    else
        printf("%sTarget NOT found!%s\n", RED, RESET);
    getchar();
}


bool intLSearch(int size, int *e, int k, int *index)
{
    for(int i = 0; i < size; i++)
    {
        if(e[i] == k)
        {
            (*index) = i + 1;
            return true;
        }
    }
    return false;
}


#endif // LINEAR_SEARCH_H