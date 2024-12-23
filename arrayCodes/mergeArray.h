void merge1(int e1[], int e2[], int size1, int size2);


void mergeArray()
{
    clearScreen();
    int arr_size1, arr_size2;

    printf("----- %sMerge Array%s -----\n", GRN, RESET);
    printf("Enter size of array 1: ");
    while(scanf("%d", &arr_size1) != 1 || arr_size1 <= 0)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int e1[arr_size1];

    printf("Enter %d elements:\n", arr_size1);
    for(int i = 0; i < arr_size1; i++)
    {
        while(scanf("%d", &e1[i]) != 1)
        {
            printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            return;
        }
    }


    printf("Enter size of array 2: ");
    while(scanf("%d", &arr_size2) != 1 || arr_size2 <= 0)
    {
        printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
        while(getchar() != '\n');
        getchar();
        return;
    }

    int e2[arr_size2];

    printf("Enter %d elements:\n", arr_size2);
    for(int i = 0; i < arr_size2; i++)
    {
        while(scanf("%d", &e2[i]) != 1)
        {
            printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
            while(getchar() != '\n');
            getchar();
            return;
        }
    }

    int size1 = sizeof(e1)/sizeof(e1[0]);
    int size2 = sizeof(e2)/sizeof(e2[0]);

    merge1(e1, e2, size1, size2);
    getchar();
    getchar();
}


void merge1(int e1[], int e2[], int size1, int size2)
{
    int mergearrays[size1 + size2];

    for(int i = 0; i < size1; i++)
        mergearrays[i] = e1[i];

    for(int i = 0; i < size2; i++)
        mergearrays[size1 + i] = e2[i];


    clearScreen();
    printf("----%sMerged-Arrays%s----\n", GRN, RESET);
    for(int i = 0; i < size1 + size2; i++)
        printf("%d ",  mergearrays[i]);
}