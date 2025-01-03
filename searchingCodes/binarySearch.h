#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
int intBSearch(int *e, int target, int l, int r);


void binarySearch(int size, int *e)
{
    clearScreen();
    int num, index = 0; 
    binarySort(size, e);
    
    printf("-------------- %sBinary Search%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    printf("Enter element to find: "); 
    while(scanf("%d", &num) != 1)
    {
        printf("%sInvalid Input!%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("-------------- %sBinary Search%s -------------------\n", GRN, RESET);
        displayIntegers(size, e);
        printf("Enter element to find: "); 
    }

    int l = 0, r = size - 1;

    clearScreen();
    printf("-------------- %sBinary Search%s -------------------\n", GRN, RESET);
    displayIntegers(size, e);
    index = intBSearch(e, num, l, r);
    if(index == -1)
        printf("%sTarget NOT found!%s\n", RED, RESET);
    else
    {
        printf("%sTarget Found!%s\n", GRN, RESET);
        printf("Target: %d\n", num);
        printf("Index: %d\n", index + 1);
        printf("Time Complexity: O(log n)\n");
        printf("Space Complexity: O(1)\n");
    }
    getchar();
}


int intBSearch(int *e, int target, int l, int r)
{
    if(l > r)
        return -1;

    int mid = l + (r - l) / 2;

    if(e[mid] == target)
        return mid;
    else if(e[mid] > target)
        return intBSearch(e, target, l, mid - 1);
    else
        return intBSearch(e, target, mid + 1, r);
}

#endif