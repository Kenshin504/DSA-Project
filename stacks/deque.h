typedef struct DequeNode
{
    int value;  
    struct DequeNode *next;
    struct DequeNode *prev;
} DequeNode;


typedef struct
{
    DequeNode *front;
    DequeNode *rear;
    int size;
    int capacity;
} Deque;


Deque *createDeque(int capacity);
int dSize(Deque *deque);
bool dIsEmpty(Deque *deque);
bool dIsFull(Deque *deque);
void enqueueFront(Deque *deque, int value);
void enqueueRear(Deque *deque, int value);
int dequeueFront(Deque *deque, bool *status);
int dequeueRear(Deque *deque, bool *status);
int peekFront(Deque *deque, bool *status);
int peekRear(Deque *deque, bool *status);
void destroyDeque(Deque *deque);
void displayDeque(Deque *deque);


void deque()
{
    int ch;
    int numDeque, value;
    bool status;

    clearScreen();
    printf("----------------- %sDeque%s ------------------\n", GRN, RESET);
    printf("Enter the maximum size of the deque: ");
    while (scanf("%d", &numDeque) != 1 || numDeque <= 0)
    {
        printf("%sInvalid Input%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("----------------- %sDeque%s ------------------\n", GRN, RESET);
        printf("Enter the maximum size of the deque: ");
    }

    Deque *deque = createDeque(numDeque);

    while (1)
    {
        clearScreen();
        printf("-------------- %sDeque Menu%s --------------\n", GRN, RESET);
        printf("[1] Enqueue Front\n");
        printf("[2] Enqueue Rear\n");
        printf("[3] Dequeue Front\n");
        printf("[4] Dequeue Rear\n");
        printf("[5] Peek Front\n");
        printf("[6] Peek Rear\n");
        printf("[7] Check Empty\n");
        printf("[8] Display Elements\n");
        printf("[9] Exit\n");
        printf("-------------------------------------------\n");
        printf("Response: ");
        while (scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("-------------- %sDeque Menu%s --------------\n", GRN, RESET);
            printf("[1] Enqueue Front\n");
            printf("[2] Enqueue Rear\n");
            printf("[3] Dequeue Front\n");
            printf("[4] Dequeue Rear\n");
            printf("[5] Peek Front\n");
            printf("[6] Peek Rear\n");
            printf("[7] Check Empty\n");
            printf("[8] Display Elements\n");
            printf("[9] Exit\n");
            printf("-------------------------------------------\n");
            printf("Response: ");
        }

        switch (ch)
        {
            case 1:
                if(dIsFull(deque))
                    printf("%sQueue is full! Cannot enqueue more elements.\n%s", RED, RESET);
                else
                {
                    clearScreen();
                    printf("---------- %sEnqueue Front%s ------------\n", GRN, RESET);
                    printf("Enter value to enqueue: ");
                    while (scanf("%d", &value) != 1)
                    {
                        printf("%sInvalid Input!%s", RED, RESET);
                        clearBuffer();
                        getchar();
                        clearScreen();
                        printf("---------- %sEnqueue Front%s ------------\n", GRN, RESET);
                        printf("Enter value to enqueue: ");
                    }
                    enqueueFront(deque, value);
                    printf("%sEnqueued %d at the front!%s", GRN, value, RESET);
                }
                clearBuffer();
                getchar();
                break;

            case 2:
                if(dIsFull(deque))
                    printf("%sQueue is full! Cannot enqueue more elements.\n%s", RED, RESET);
                else
                {
                    clearScreen();
                    printf("---------- %sEnqueue Rear%s ------------\n", GRN, RESET);
                    printf("Enter value to enqueue: ");
                    while (scanf("%d", &value) != 1)
                    {
                        printf("%sInvalid Input!%s", RED, RESET);
                        clearBuffer();
                        getchar();
                        clearScreen();
                        printf("---------- %sEnqueue Rear%s ------------\n", GRN, RESET);
                        printf("Enter value to enqueue: ");
                    }
                    enqueueRear(deque, value);
                    printf("%sEnqueued %d at the rear!%s", GRN, value, RESET);
                }
                clearBuffer();
                getchar();
                break;

            case 3:
                value = dequeueFront(deque, &status);
                if (status)
                    printf("%sDequeued %d from the front.%s\n", GRN, value, RESET);
                else
                    printf("%sDeque is empty!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;

            case 4:
                value = dequeueRear(deque, &status);
                if (status)
                    printf("%sDequeued %d from the rear.%s\n", GRN, value, RESET);
                else
                    printf("%sDeque is empty!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;

            case 5:
                value = peekFront(deque, &status);
                if (status)
                    printf("%sFront value: %d%s\n", GRN, value, RESET);
                else
                    printf("%sDeque is empty!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;

            case 6:
                value = peekRear(deque, &status);
                if (status)
                    printf("%sRear value: %d%s\n", GRN, value, RESET);
                else
                    printf("%sDeque is empty!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;

            case 7:
                if (dIsEmpty(deque))
                    printf("%sDeque is empty.%s\n", GRN, RESET);
                else
                    printf("%sDeque is not empty.%s\nSize of Deque: %d\n", YEL, RESET, deque->size);
                clearBuffer();
                getchar();
                break;

            case 8:
                clearScreen();
                printf("---------- %sDisplay All Elements%s ------------\n", GRN, RESET);
                displayDeque(deque);
                clearBuffer();
                getchar();
                break;

            case 9:
                destroyDeque(deque);
                printf("%sDeqeu destroyed.%s\n", GRN, RESET);
                clearBuffer();
                getchar();
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}


Deque *createDeque(int capacity)
{
    if(capacity <= 0) return NULL;

    Deque *deque = malloc(sizeof(Deque));
    if(deque == NULL)
    {
        printf("Memory allocation failed!");
        clearBuffer();
        getchar();
        return NULL;
    }

    deque->front = NULL;
    deque->rear = NULL;
    deque->size = 0;
    deque->capacity = capacity;

    return deque;
}


int dSize(Deque *deque)
{
    return deque->size;
}


bool dIsEmpty(Deque *deque)
{
    return (deque->size == 0);
}


bool dIsFull(Deque *deque)
{
    return (deque->size >= deque->capacity);
}


void enqueueFront(Deque *deque, int value)
{
    if(dIsFull(deque))
    {
        printf("%sDeque is Full!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        return;
    }

    DequeNode *newNode = malloc(sizeof(DequeNode));
    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        clearBuffer();
        return;
    }

    newNode->value = value;
    newNode->next = deque->front;
    newNode->prev = NULL;

    if(dIsEmpty(deque))
        deque->rear = newNode;
    else
        deque->front->prev = newNode;

    deque->front = newNode;
    deque->size++;
}


void enqueueRear(Deque *deque, int value)
{
    if(dIsFull(deque))
    {
        printf("%sDeque is Full!%s\n", RED, RESET);
        clearBuffer();
        getchar();
        return;
    }

    DequeNode *newNode = malloc(sizeof(DequeNode));
    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        clearBuffer();
        getchar();
        return;
    }

    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;

    if(dIsEmpty(deque))
        deque->front = newNode;
    else
        deque->rear->next = newNode;

    deque->rear = newNode;
    deque->size++;
}


int dequeueFront(Deque *deque, bool *status)
{
    if(dIsEmpty(deque))
    {
        *status = false;
        return -1;
    }

    *status = true;
    int value = deque->front->value;

    DequeNode *oldFront = deque->front;
    deque->front = deque->front->next;

    if(deque->front == NULL)
        deque->rear = NULL;
    else
        deque->front->prev = NULL;

    free(oldFront);
    deque->size--;
    return value;
}


int dequeueRear(Deque *deque, bool *status)
{
    if(dIsEmpty(deque))
    {
        *status = false;
        return -1;
    }

    *status = true;
    int value = deque->rear->value;

    DequeNode *oldRear = deque->rear;
    deque->rear = deque->rear->prev;

    if(deque->rear == NULL)
        deque->front = NULL;
    else
        deque->rear->next = NULL;

    free(oldRear);
    deque->size--;
    return value;
}


int peekFront(Deque *deque, bool *status) 
{
    if (dIsEmpty(deque)) 
    {
        *status = false;
        return -1;
    }
    *status = true;
    return deque->front->value;
}

int peekRear(Deque *deque, bool *status) 
{
    if (dIsEmpty(deque)) 
    {
        *status = false;
        return -1;
    }
    *status = true;
    return deque->rear->value;
}

void destroyDeque(Deque *deque) 
{
    while (!dIsEmpty(deque)) 
    {
        bool status;
        dequeueFront(deque, &status);
    }
    free(deque);
}


void displayDeque(Deque *deque)
{
    if (dIsEmpty(deque))
    {
        printf("%sDeque is empty!%s\n", RED, RESET);
        return;
    }

    printf("Deque elements: ");
    DequeNode *current = deque->front;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}