#include "linearSearch.h"
#include "binarySearch.h"


void SearchingMenu(int size, int *e);


void Searching()
{
    clearScreen();

    int arr_size;
    int *e = NULL;
    int ch;

    printf("----------- %sSearching Operations%s ---------------\n", GRN, RESET);
    printf("[1] Input Elements\n");
    printf("[2] Generate Elements\n");
    printf("[3] Exit\n");
    printf("--------------------------------------------------\n");
    printf("Response: ");
    while(scanf("%d", &ch) != 1)
    {
        printf("%sInvalid Input.%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("----------- %sSearching Operations%s ---------------\n", GRN, RESET);
        printf("[1] Input Elements\n");
        printf("[2] Generate Elements\n");
        printf("[3] Exit\n");
        printf("--------------------------------------------------\n");
        printf("Response: ");
    }

    switch(ch)
    {
        case 1:          
            inputElement(&arr_size, &e);
            SearchingMenu(arr_size, e);
            getchar();
            break;

        case 2:
            generateElement(&arr_size, &e);
            SearchingMenu(arr_size, e);
            getchar();
            break;
    }
}


void SearchingMenu(int size, int *e)
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sSearching Menu%s ----\n", GRN, RESET);
        printf("[1] Linear Search\n");
        printf("[2] Binary Search\n");
        printf("[3] Exit\n");
        printf("-----------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sSearching Menu%s ----\n", GRN, RESET);
            printf("[1] Linear Search\n");
            printf("[2] Binary Search\n");
            printf("[3] Exit\n");
            printf("-----------------------\n");
            printf("Response: ");
        }
        
        switch(ch)
        {
            case 1:
                linearSearch(size, e);
                getchar();
                break;
            
            case 2:
                binarySearch(size, e);
                getchar();
                break;

            case 3:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                 break;
        }
    }
}