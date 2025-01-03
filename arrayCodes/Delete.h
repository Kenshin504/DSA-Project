#ifndef DELETE_H
#define DELETE_H


void deleteElement(int *size, int **e, int position);


void Delete(int *size, int **e)
{
    clearScreen();
    int pos;

    printf("------------ %sDelete Element%s ----------------\n", GRN, RESET);
    printf("Enter the position to delete [1 - %d]: ", *size);
    while (scanf("%d", &pos) != 1 || pos < 1 || pos > *size + 1)
    {
        printf("%sInvalid Input!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("------------ %sDelete Element%s ----------------\n", GRN, RESET);
        printf("Enter the position to delete [1 - %d]: ", *size);
    }

    deleteElement(size, e, pos);
}


void deleteElement(int *size, int **e, int position)
{
    if (position < 1 || position > *size)
    {
        printf("%sInvalid position! Valid range: 1 to %d.%s\n", RED, *size, RESET);
        return;
    }
    int adjustedPosition = position - 1;

    for (int i = adjustedPosition; i < *size - 1; i++)
    {
        (*e)[i] = (*e)[i + 1];
    }

    *e = realloc(*e, (*size - 1) * sizeof(int));
    if (*e == NULL && *size - 1 > 0) // Check if allocation fails but not for empty array
    {
        printf("Memory reallocation failed!\n");
        return;
    }

    (*size)--;
    printf("%sElement deleted successfully from position %d!%s\n", GRN, position, RESET);
}

#endif