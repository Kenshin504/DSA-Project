#include <stdio.h>
#include "mainMenu.h"


void main()
{
    getchar();

    while(1)
    {
        clearScreen();
        printf("---- %sData-Structures-and-Algorithms%s ----\n\n", GRN, RESET);
        printf("        Lumbis Ryan M   BSIT-2C\n");
        printf("       Ctrl-Z or Crtrl-D to exit\n");
        printf("        Press Enter to continue...");
        while(getchar() != '\n');
        clearBuffer();

        mainMenu();
    }
}