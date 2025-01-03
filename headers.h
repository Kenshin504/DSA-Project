#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>


#define sline "--------------------------------------\n"
#define RESET "\033[0m"
#define BLK "\033[0;30m"
#define RED "\033[0;31m"
#define GRN "\033[0;32m"
#define YEL "\033[0;33m"
#define BLU "\033[0;34m"
#define MGT "\033[0;35m"
#define CYN "\033[0;36m"
#define WHT "\033[0;37m"


void clearScreen(void);
void bSort(int e[], int size);
void swaps(int *a, int *b);
void generate(int *size, int **e);
void charSwaps(char *a, char *b);
void displayIntegers(int size, int e[]);
void clearBuffer();
void inputElement(int *size, int **e);
void generateElement(int *size, int **e);


int ch;


void clearScreen(void)
{
    printf("\033[H\033[J");
}


void bSort(int e[], int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(e[j] > e[j + 1])
                swaps(&e[j], &e[j + 1]);
        }
    }
}


void swaps(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void generate(int *size, int **e)
{
    srand(time(NULL));

    int count = 0; // Counter to track how many unique numbers have been generated
    while (count < *size)
    {
        int num = rand() % 99; // Generate a random number between 0 and 98
        int isDuplicate = 0;

        // Check if the generated number already exists in the array
        for (int i = 0; i < count; i++)
        {
            if ((*e)[i] == num)
            {
                isDuplicate = 1; // Mark as duplicate if found
                break;
            }
        }

        // If it's not a duplicate, add it to the array
        if (!isDuplicate)
        {
            (*e)[count] = num;
            count++; // Increment the count of unique numbers
        }
    }
}


void charSwaps(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void displayIntegers(int size, int *e)
{
    for(int i = 0; i < size; i++)
        printf("%s%d%s ", BLU, e[i], RESET);

    printf("\n");
}


void displayCharacters(char e[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%c ", e[i]);

    printf("\n");
}


void clearBuffer()
{
    int c; 
    while((c = getchar()) != '\n' && c != EOF); 
}


void inputElement(int *size, int **e)
{
    clearScreen();
    
    printf("-------------- %sInput Elements%s ------------------\n", GRN, RESET);
    printf("Enter size of elements: ");
    while(scanf("%d", size) != 1 || *size <= 0)
    {
        printf("%sInvalid Input.%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("-------------- %sInput Elements%s ------------------\n", GRN, RESET);
        printf("Enter size of elements: ");
    }

    *e = malloc(*size * sizeof(int));

    clearScreen();
    printf("-------------- %sInput Elements%s ------------------\n", GRN, RESET);
    printf("Enter %d elements: ", *size);
    
    for(int i = 0; i < *size; i++)
    {
        while(scanf("%d", &(*e)[i]) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("-------------- %sInput Elements%s ------------------\n", GRN, RESET);
            printf("Enter %d elements: ", *size);
        }
    }
}


void generateElement(int *size, int **e)
{
    clearScreen();
    
    printf("-------------- %sGenerate Elements%s ------------------\n", GRN, RESET);
    printf("Enter size of elements: ");
    while(scanf("%d", size) != 1 || *size <= 0)
    {
        printf("%sInvalid Input.%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("-------------- %sGenerate Elements%s ------------------\n", GRN, RESET);
        printf("Enter size of elements: ");
    }

    *e = malloc(*size * sizeof(int));

    generate(size, e);
}


void binarySort(int size, int *e)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(e[j] > e[j + 1])
            {
                int temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}


void shuffleArray(int *e, int size)
{
    srand(time(NULL));

    for(int i = size - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swaps(&e[i], &e[j]);
    }
}