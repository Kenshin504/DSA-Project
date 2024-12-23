typedef struct 
{
    int *collection;
    int capacity;
    int size;
} Stack;


Stack *createStack(int capacity);
void destroyStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
bool sPop(Stack *stack, int *item);
bool sPush(Stack *stack, int item);
bool sPeek(Stack *stack, int *item);
void displayStack(Stack *stack);


void stacks()
{
    int ch;
    int numStack;
    int num;
    int peekVal = 0;
    int popVal = 0;
    bool check;

    clearScreen();
    printf("-------- %sStacks%s --------\n", GRN, RESET);
    printf("Enter size of stack: ");
    while(scanf("%d", &numStack) != 1 || numStack <= 0)
    {
        printf("%sInvalid Input. Please enter a positive integer!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("-------- %sStacks%s --------\n", GRN, RESET);
        printf("Enter size of stack: ");
    }

    Stack *stack = createStack(numStack);

    while(1) 
    {
        clearScreen();
        printf("--------- %sStacks Menu%s -----------\n", GRN, RESET);
        printf("[1] Push\n");
        printf("[2] Pop\n");
        printf("[3] Check Empty\n");
        printf("[4] Display Peek\n");
        printf("[5] Display Elements\n");
        printf("[6] Exit\n");
        printf("---------------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("--------- %sStacks Menu%s -----------\n", GRN, RESET);
            printf("[1] Push\n");
            printf("[2] Pop\n");
            printf("[3] Check Empty\n");
            printf("[4] Display Peek\n");
            printf("[5] Display Elements\n");
            printf("[6] Exit\n");
            printf("---------------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                clearScreen();
                printf("---- %sStack Push%s ----\n", GRN, RESET);
                printf("Enter an integer: ");
                while(scanf("%d", &num) != 1)
                {
                    printf("%sInvalid Input!%s\n", RED, RESET);
                    clearBuffer();
                    getchar();
                    clearScreen();
                    printf("---- %sStack Push%s ----\n", GRN, RESET);
                    printf("Enter an integer: ");
                }
                sPush(stack, num);
                getchar();
                break;

            case 2:
                clearScreen();
                check = sPop(stack, &popVal);
                if(check == true)
                {
                    printf("----- %sPop Stack%s -----\n", GRN, RESET);
                    printf("%d is now popped!\n", popVal);
                    clearBuffer();
                    //getchar();
                }
                getchar();
                break;

            case 3:
                check = isEmpty(stack);
                if(check == true)
                {
                    printf("%sThe stack is Empty!%s", RED, RESET);
                    clearBuffer();
                    getchar();
                }
                else 
                {
                    printf("%sThe stack size is %d%s\n", GRN, stack->size, RESET);
                    clearBuffer();
                    getchar();
                }
                break;

            case 4:
                clearScreen();
                check = sPeek(stack, &peekVal);
                if(check == true)
                {
                    printf("----- %sPeek Value%s -----\n", GRN, RESET);
                    printf("Top: %d\n", peekVal);
                    clearBuffer();
                    //getchar();
                }
                getchar();
                break;

            case 5:
            clearScreen();
            printf("----- %sDisplay Stack%s -----\n", GRN, RESET);
            displayStack(stack);
            clearBuffer();
            getchar();
            break;

            case 6:
                destroyStack(stack);
                getchar();
                return;
                
            default:
                printf("%sInvalid Input!%s\n", RED, RESET);
                getchar();
                getchar();
        }
    }
}


Stack *createStack(int capacity)
{
    if(capacity <= 0) return NULL;

    Stack *stack = malloc(sizeof(Stack));
    if(stack == NULL)
    {
        printf("Memory allocation failed.\n");
        getchar();
        return NULL;
    }

    stack->collection = malloc(sizeof(int) * capacity);
    if(stack->collection == NULL)
    {
        printf("Memory allocation failed.\n"); 
        getchar();
        free(stack);
        return NULL;
    }

    stack->capacity = capacity;
    stack->size = 0;

    return stack;
}


void destroyStack(Stack *stack)
{
    free(stack->collection);
    free(stack);

    printf("\n%sStack is successfully destroyed.%s\n", GRN, RESET);
}


bool isFull(Stack *stack)
{
    return stack->capacity == stack->size;
}


bool isEmpty(Stack *stack)
{
    return stack->size == 0;
}


bool sPush(Stack *stack, int item)
{
    if(isFull(stack))
    {
        printf("%sThe stack is full!%s", RED, RESET);
        getchar();
        return false;
    }

    stack->collection[stack->size] = item;
    stack->size++;


    printf("\n%sItem successfully pushed!%s", GRN, RESET);
    getchar();
    return true;
}


bool sPeek(Stack *stack, int *item)
{
    if(isEmpty(stack))
    {
        printf("%sThe stack is empty!%s\n", RED, RESET);
        getchar();
        return false;
    }

    *item = stack->collection[stack->size - 1];

    return true;
}


bool sPop(Stack *stack, int *item)
{
    if(isEmpty(stack))
    {
        printf("%sThe stack is empty!%s\n", RED, RESET);
        getchar();
        return false;
    }

    stack->size--;
    *item = stack->collection[stack->size];
    
    return true;
}


void displayStack(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("%sThe stack is empty!%s\n", RED, RESET);
        return;
    }

    printf("Stack elements (top to bottom): ");
    for (int i = stack->size - 1; i >= 0; i--)
    {
        printf("%d ", stack->collection[i]);
    }
    printf("\n");
}