#ifndef INSERT_H
#define INSERT_H

void insertElement(int *size, int **e, int position, int value);

void Insert(int *size, int **e)
{
    clearScreen();
    int pos, val;

    printf("------------ %sInsert Element%s ----------------\n", GRN, RESET);
    printf("Enter the position to insert [1 - %d]: ", *size + 1);
    while (scanf("%d", &pos) != 1 || pos < 1 || pos > *size + 1)
    {
        printf("%sInvalid Input!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("------------ %sInsert Element%s ----------------\n", GRN, RESET);
        printf("Enter the position to insert [1 - %d]: ", *size + 1);
    }

    clearScreen();
    printf("------------ %sInsert Element%s ----------------\n", GRN, RESET);
    printf("Enter an integer value to insert: ");
    while (scanf("%d", &val) != 1)
    {
        printf("%sInvalid Input!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("------------ %sInsert Element%s ----------------\n", GRN, RESET);
        printf("Enter an integer value to insert: ");
    }

    insertElement(size, e, pos, val);
}

void insertElement(int *size, int **e, int position, int value)
{
    // Validate position (1-based indexing)
    if (position < 1 || position > *size + 1)
    {
        printf("%sInvalid position! Valid range: 1 to %d.%s\n", RED, *size + 1, RESET);
        return;
    }

    // Adjust position to 0-based indexing
    int adjustedPosition = position - 1;

    // Dynamically increase the size of the array
    *e = realloc(*e, (*size + 1) * sizeof(int));
    if (*e == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > adjustedPosition; i--)
    {
        (*e)[i] = (*e)[i - 1];
    }

    // Insert the new element
    (*e)[adjustedPosition] = value;

    // Increase the size
    (*size)++;
    printf("%sElement inserted successfully at position %d!%s\n", GRN, position, RESET);
}

#endif