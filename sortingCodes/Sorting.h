#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "CountingSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "RadixSort.h"
#include "HeapSort.h"


void SortingMenu(int size, int *e);

void Sorting()
{
        clearScreen();

    int arr_size;
    int *e = NULL;
    int ch;

    printf("----------- %sSorting Operations%s ---------------\n", GRN, RESET);
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
        printf("----------- %sSorting Operations%s ---------------\n", GRN, RESET);
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
            SortingMenu(arr_size, e);
            getchar();
            break;

        case 2:
            generateElement(&arr_size, &e);
            SortingMenu(arr_size, e);
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


void SortingMenu(int size, int *e)
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("--------- %sSorting Operations%s -----------\n", GRN, RESET);
        displayIntegers(size, e);
        printf("[1] Shuffle Elements\n");
        printf("[2] Bubble Sort\n");
        printf("[3] Selection Sort\n");
        printf("[4] Insertion Sort\n");
        printf("[5] Counting Sort\n");
        printf("[6] Merge Sort\n");
        printf("[7] Quick Sort\n");
        printf("[8] Radix Sort\n");
        printf("[9] Heap Sort\n");
        printf("[10] Exit\n");
        printf("-------------------------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("--------- %sSorting Operations%s -----------\n", GRN, RESET);
            displayIntegers(size, e);
            printf("[1] Shuffle Elements\n");
            printf("[2] Bubble Sort\n");
            printf("[3] Selection Sort\n");
            printf("[4] Insertion Sort\n");
            printf("[5] Counting Sort\n");
            printf("[6] Merge Sort\n");
            printf("[7] Quick Sort\n");
            printf("[8] Radix Sort\n");
            printf("[9] Heap Sort\n");
            printf("[10] Exit\n");
            printf("-------------------------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                shuffleArray(e, size);
                break;

            case 2:
                BubbleSort(e, size);
                printf("\n%sBubble Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n)\n");
                printf("Space Complexity: O(1)\n");
                getchar();
                getchar();
                break;

            case 3:
                SelectionSort(e, size);
                printf("\n%sSelection Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n^2)\n");
                printf("Space Complexity: O(1)\n");
                getchar();
                getchar();
                break;

            case 4:
                InsertionSort(e, size);
                printf("\n%sInsertion Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n^2)\n");
                printf("Space Complexity: O(1)\n");
                getchar();
                getchar();
                break;

            case 5:
                CountingSort(e, size);
                printf("\n%sCounting Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n + m)\n");
                printf("Space Complexity: O(k + n)\n");
                getchar();
                getchar();
                break;

            case 6:
                MergeSort(e, 0, size - 1);
                printf("\n%sMerge Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n log n)\n");
                printf("Space Complexity: O(n)");
                getchar();
                getchar();
                break;

            case 7:
                QuickSort(e, 0, size - 1);
                printf("\n%sQuick Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n log n)\n");
                printf("Space Complexity: O(n)");
                getchar();
                getchar();
                break;

            case 8:
                RadixSort(e, size);
                printf("\n%sRadix Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(d *(n + b))\n");
                printf("Space Complexity: O(n + k)");
                getchar();
                getchar();
                break;

            case 9:
                HeapSort(e, size);
                printf("\n%sHeap Sort%s\n", GRN, RESET);
                printf("Time Complexity: O(n log n)\n");
                printf("Space Complexity: O(1)\n");
                getchar();
                getchar();
                break;
    
            case 10:
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