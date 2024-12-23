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
void generate(int size, int e[]);
void charSwaps(char *a, char *b);
void displayIntegers(int size, int e[]);
void clearBuffer();


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


void generate(int size, int e[])
{
    for(int i = 0; i < size; i++)
        e[i] = i + 1;
}


void charSwaps(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}


void displayIntegers(int size, int e[])
{
    for(int i = 0; i < size; i++)
        printf("%d ", e[i]);

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