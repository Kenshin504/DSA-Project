void deleteArray()
{
    clearScreen();
    int arr_size;
    int pos;

    printf("---- %sDelete Array%s ----\n", GRN, RESET);
    printf("Enter size of the array: ");
    while(scanf("%d", &arr_size) != 1 || arr_size <= 0) {
        printf("Invalid input! Please enter a positive integer.\n");
        while(getchar() != '\n'); 
        getchar();
        return; 
    }

    int e[arr_size];  

    printf("Enter %d elements:\n", arr_size);
    for(int i = 0; i < arr_size; i++) {
        while(scanf("%d", &e[i]) != 1) {
            printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
            while(getchar() != '\n'); 
            getchar();
            return;  
        }
    }

   
    printf("Enter index (0-based) to delete the element: ");
    while(scanf("%d", &pos) != 1 || pos < 0 || pos >= arr_size) {
        printf("%sInvalid position! Enter a value between 0 and %d.%s\n", RED, arr_size - 1, RESET);
        while(getchar() != '\n');  
        getchar();
        return;  
    }

    for(int i = pos; i < arr_size - 1; i++) {
        e[i] = e[i + 1];
    }

    printf("\n%sUpdated array after deletion:%s\n", GRN, RESET);
    for(int i = 0; i < arr_size - 1; i++) {
        printf("%d ", e[i]);
    }
    printf("\n");

    getchar();  
    getchar();  

}