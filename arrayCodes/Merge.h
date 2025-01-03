#ifndef MERGE_H
#define MERGE_H

void mergeArrays(int *size1, int **e1, int size2, int *e2);

void Merge(int *size, int **e)
{
    clearScreen();
    int size2, ch;
    int *e2 = NULL;

    printf("------------ %sMerge Arrays%s ----------------\n", GRN, RESET);
    printf("Enter the size of the second array: ");
    while (scanf("%d", &size2) != 1 || size2 <= 0)
    {
        printf("%sInvalid Input!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("Enter the size of the second array: ");
    }

    e2 = malloc(size2 * sizeof(int));
    if (e2 == NULL)
    {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        return;
    }

    printf("----------- %sSecond Array Operations%s ---------------\n", GRN, RESET);
    printf("[1] Input Elements\n");
    printf("[2] Generate Elements\n");
    printf("--------------------------------------------------\n");
    printf("Response: ");
    while (scanf("%d", &ch) != 1 || (ch < 1 || ch > 2))
    {
        printf("%sInvalid Input.%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("[1] Input Elements\n");
        printf("[2] Generate Elements\n");
        printf("Response: ");
    }

    if (ch == 1)
    {
        inputElement(&size2, &e2);
    }
    else
    {
        generateElement(&size2, &e2);
    }

    mergeArrays(size, e, size2, e2);
    free(e2);
    getchar();
}

void mergeArrays(int *size1, int **e1, int size2, int *e2)
{
    *e1 = realloc(*e1, (*size1 + size2) * sizeof(int));
    if (*e1 == NULL)
    {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        return;
    }

    for (int i = 0; i < size2; i++)
    {
        (*e1)[*size1 + i] = e2[i];
    }

    *size1 += size2;
    printf("%sArrays merged successfully! New size: %d.%s\n", GRN, *size1, RESET);
}

#endif
