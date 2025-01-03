#include "headers.h"
#include "String/insert.h"
#include "String/replace.h"
#include "String/delete.h"
#include "String/concatenation.h"
#include "String/length.h"
#include "String/substring.h"
#include "String/comparison.h"
#include "String/characterAccess.h"
//#include "arrayCodes/insertArray.h"
///#include "arrayCodes/deleteArray.h"
//#include "arrayCodes/mergeArray.h"
#include "linkedListCodes/singlyLinkedList.h"
#include "linkedListCodes/doublyLinkedList.h"
#include "PDT/boolean.h"
#include "PDT/integer.h"
#include "PDT/character.h"
#include "PDT/float.h"
#include "PDT/double.h"
#include "stacks/stacks.h"
#include "stacks/queues.h"
#include "stacks/deque.h"
#include "nonLinear/graph.h"
#include "nonLinear/tree.h"
#include "searchingCodes/Searching.h"
#include "searchingCodes/linearSearch.h"
#include "searchingCodes/binarySearch.h"
#include "sortingCodes/Sorting.h"
#include "arrayCodes/Arrays.h"


void pDataTypes();
void nonPDataTypes();
void linearMenu();
void nonLinearMenu();
void arraysMenu();
void stringMenu();
void linkedListMenu();
void stackQueuesMenu();


void mainMenu()
{
    while(1)
    {
        int ch;
        clearScreen(); 
        printf("---- %sData Structures and Algorithms%s ----\n", GRN, RESET);
        printf("[1] Primitive Data Types\n");
        printf("[2] Non-Primitive Data Types\n");
        printf("[3] Exit\n%s", sline);
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sData Structures and Algorithms%s ----\n", GRN, RESET);
            printf("[1] Primitive Data Types\n");
            printf("[2] Non-Primitive Data Types\n");
            printf("[3] Exit\n%s", sline);
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                pDataTypes();
                break;

            case 2:
                nonPDataTypes();
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

void pDataTypes()
{
    int ch;
    
    while(1)
    {
        clearScreen(); 
        printf("---- %sPrimitive Data Types%s ----\n", GRN, RESET);
        printf("[1] Boolean\n");
        printf("[2] Integer\n");
        printf("[3] Char\n");
        printf("[4] Float\n");
        printf("[5] Double\n");
        printf("[6] Exit\n%s", sline);
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sPrimitive Data Types%s ----\n", GRN, RESET);
            printf("[1] Boolean\n");
            printf("[2] Integer\n");
            printf("[3] Char\n");
            printf("[4] Float\n");
            printf("[5] Double\n");
            printf("[6] Exit\n%s", sline);
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                boolean();
                getchar();
                break;

            case 2:
                integer();
                getchar();
                break;

            case 3:
                character();
                getchar();
                break;

            case 4:
                pFloat();
                getchar();
                break;

            case 5:
                pDouble();
                getchar();
                break;

            case 6:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}

void nonPDataTypes()
{
    int ch;

    while(1)
    {
        clearScreen(); 
        printf("---- %sNon Primitive Data Types%s ----\n", GRN, RESET);
        printf("[1] Linear\n");
        printf("[2] Non-Linear\n");
        printf("[3] Exit\n%s", sline);
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sNon Primitive Data Types%s ----\n", GRN, RESET);
            printf("[1] Linear\n");
            printf("[2] Non-Linear\n");
            printf("[3] Exit\n%s", sline);
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                linearMenu();
                break;

            case 2:
                nonLinearMenu();
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


void linearMenu()
{
    int ch; 
    while(1)
    {
        clearScreen();
        printf("----- %sLinear Menu%s -----\n", GRN, RESET);
        printf("[1] Arrays\n");
        printf("[2] Strings\n");
        printf("[3] Linked List\n");
        printf("[4] Stacks & Queus\n");
        printf("[5] Exit\n");
        printf("---------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("----- %sLinear Menu%s -----\n", GRN, RESET);
            printf("[1] Arrays\n");
            printf("[2] Strings\n");
            printf("[3] Linked List\n");
            printf("[4] Stacks & Queus\n");
            printf("[5] Exit\n");
            printf("---------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                arraysMenu();
                break;
            
            case 2:
                stringMenu();
                break;

            case 3:
                linkedListMenu();
                break;

            case 4:
                stackQueuesMenu();
                break;

            case 5:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


void nonLinearMenu()
{
    int ch; 
    while(1)
    {
        clearScreen();
        printf("---- %sNon Linear Menu%s ----\n", GRN, RESET);
        printf("[1] Tree\n");
        printf("[2] Graph\n");
        printf("[3] Exit\n");
        printf("------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sNon Linear Menu%s ----\n", GRN, RESET);
            printf("[1] Tree\n");
            printf("[2] Graph\n");
            printf("[3] Exit\n");
            printf("------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                tree();
                break;

            case 2:
                graph();
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


void arraysMenu()
{
    int ch;
    while(1)
    {
        clearScreen();
        printf("---- %sArrays Menu%s ----\n", GRN, RESET);
        printf("[1] Searching\n");
        printf("[2] Sorting\n");
        printf("[3] Arrays\n");
        printf("[4] Exit\n");
        printf("--------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---- %sArrays Menu%s ----\n", GRN, RESET);
            printf("[1] Searching\n");
            printf("[2] Sorting\n");
            printf("[3] Insert\n");
            printf("[4] Delete\n");
            printf("[5] Merge\n");
            printf("[6] Exit\n");
            printf("--------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                Searching();   
                break;

            case 2:
                Sorting();
                break;

            case 3: 
                Arrays();
                break;

            case 4:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


void stringMenu()
{
    int ch;

    while(1)
    {
        clearScreen();
        printf("----- %sString Menu%s ------\n", GRN, RESET);
        printf("[1] Insert\n");
        printf("[2] Replace\n");
        printf("[3] Delete\n");
        printf("[4] Concatenation\n");
        printf("[5] Substring\n");
        printf("[6] Length\n");
        printf("[7] Comparison\n");
        printf("[8] Character Access\n");
        printf("[9] Exit\n");
        printf("---------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("----- %sString Menu%s ------\n", GRN, RESET);
            printf("[1] Insert\n");
            printf("[2] Replace\n");
            printf("[3] Delete\n");
            printf("[4] Concatenation\n");
            printf("[5] Substring\n");
            printf("[6] Length\n");
            printf("[7] Comparison\n");
            printf("[8] Character Access\n");
            printf("[9] Exit\n");
            printf("---------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1: 
                insert();
                break;

            case 2:
                replace();
                break;

            case 3:
                delete();
                break;

            case 4:
                concatenation();
                break;

            case 5:
                substring();
                break;

            case 6:
                length();
                break;

            case 7:
                comparison();
                break;

            case 8:
                characterAccess();
                break;

            case 9:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


void linkedListMenu()
{
    int ch;

    while(1)
    {
        clearScreen();
        printf("----- %sLinked List Menu%s -----\n", GRN, RESET);
        printf("[1] Singly Linked List\n");
        printf("[2] Doubly Linked List\n");
        printf("[3] Exit\n");
        printf("--------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("----- %sLinked List Menu%s -----\n", GRN, RESET);
            printf("[1] Singly Linked List\n");
            printf("[2] Doubly Linked List\n");
            printf("[3] Exit\n");
            printf("--------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                singlyLinkedList();
                break;

            case 2:
                doublyLinkedList();
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


void stackQueuesMenu()
{
    int ch;

    while(1)
    {
        clearScreen();
        printf("---------- %sStacks & Queues Menu%s ----------\n", GRN, RESET);
        printf("[1] Stacks\n");
        printf("[2] Queues\n");
        printf("[3] Dequeues\n");
        printf("[4] Exit\n");
        printf("------------------------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("---------- %sStacks & Queues Menu%s ----------\n", GRN, RESET);
            printf("[1] Stacks\n");
            printf("[2] Queues\n");
            printf("[3] Deque\n");
            printf("[4] Exit\n");
            printf("------------------------------------------\n");
            printf("Response: ");
        }

        switch(ch)    
        {
            case 1:
                stacks();
                break;

            case 2:
                queues();
                break;

            case 3:
                deque();
                break;

            case 4:
                return;

            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}