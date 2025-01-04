#include "Insert.h"
#include "Delete.h"
#include "Merge.h"


void ArraysMenu(int size, int *e);


void Arrays()
{
    clearScreen();

    int arr_size;
    int *e = NULL;
    int ch;

    printf("----------- %sArrays Operations%s ---------------\n", GRN, RESET);
    printf("[1] Input Elements\n");
    printf("[2] Generate Elements\n");
    printf("[3] Exit\n");
    printf("-----------------------------------------------\n");
    printf("Response: ");
    while(scanf("%d", &ch) != 1)
    {
        printf("%sInvalid Input.%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("----------- %sArrays Operations%s ---------------\n", GRN, RESET);
        printf("[1] Input Elements\n");
        printf("[2] Generate Elements\n");
        printf("[3] Exit\n");
        printf("-----------------------------------------------\n");
        printf("Response: ");
    }

    switch(ch)
    {
        case 1:          
            inputElement(&arr_size, &e);
            ArraysMenu(arr_size, e);
            getchar();
            break;

        case 2:
            generateElement(&arr_size, &e);
            ArraysMenu(arr_size, e);
            getchar();
            break;

        case 3:
            free(e);
            return;

        default:
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            break;
    }
}


void ArraysMenu(int size, int *e)
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("----------- %sArrays Operations%s ---------------\n", GRN, RESET);
        displayIntegers(size, e);
        printf("[1] Insert Element\n");
        printf("[2] Delete Element\n");
        printf("[3] Merge Arrays\n");
        printf("[4] Exit\n");
        printf("--------------------------------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("----------- %sArrays Operations%s ---------------\n", GRN, RESET);
            displayIntegers(size, e);
            printf("[1] Insert Element\n");
            printf("[2] Delete Element\n");
            printf("[3] Merge Arrays\n");
            printf("[4] Exit\n");
            printf("--------------------------------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                Insert(&size, &e);
                getchar();
                getchar();
                break;

            case 2:
                Delete(&size, &e);
                getchar();
                getchar();
                break;

            case 3:
                Merge(&size, &e);
                getchar();
                getchar();
                break;

            case 4:
                free(e);
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}