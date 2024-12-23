typedef struct QueueNode {
    int value;
    struct QueueNode *next; 
} QueueNode;

typedef struct {
    QueueNode *head;
    QueueNode *tail;
    int size;
    int capacity; 
} Queue;


// Queue function declarations
Queue *createQueue(int capacity);
int size(Queue *queue);
bool qIsEmpty(Queue *queue);
bool qIsFull(Queue *queue);
int qPeek(Queue *queue, bool *status);
void enqueue(Queue *queue, int value);
int dequeue(Queue *queue, bool *status);
void destroyQueue(Queue *queue);
void displayQueue(Queue *queue);


// Menu driver function
void queues() {
    int ch, numQueue, value;
    bool status;

    clearScreen();
    printf("--------------- %sQueues%s -------------------\n", GRN, RESET);
    printf("Enter the maximum size of the queue: ");
    while (scanf("%d", &numQueue) != 1 || numQueue <= 0) {
        printf("%sInvalid Input! Please enter a positive number%s", RED, RESET);
        clearBuffer();
        getchar();
        clearScreen();
        printf("--------------- %sQueues%s -------------------\n", GRN, RESET);
        printf("Enter the maximum size of the queue: ");
    }

    Queue *queue = createQueue(numQueue);

    while (1) 
    {
        clearScreen();
        printf("\n-------- %sQueue Menu%s --------\n", GRN, RESET);
        printf("[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Peek\n");
        printf("[4] Check Empty\n");
        printf("[5] Check Full\n");
        printf("[6] Display Elements\n");
        printf("[7] Exit\n");
        printf("----------------------------\n");
        printf("Response: ");
        while (scanf("%d", &ch) != 1) 
        {
            printf("%sInvalid Input!%s\n", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("\n-------- %sQueue Menu%s --------\n", GRN, RESET);
            printf("[1] Enqueue\n");
            printf("[2] Dequeue\n");
            printf("[3] Peek\n");
            printf("[4] Check Empty\n");
            printf("[5] Check Full\n");
            printf("[6] Display Elements\n");
            printf("[7] Exit\n");
            printf("----------------------------\n");
            printf("Response: ");
        }

        switch (ch) {
            case 1:
                if (qIsFull(queue)) 
                    printf("%sQueue is full! Cannot enqueue more elements.\n%s", RED, RESET);
                else 
                {
                    clearScreen();
                    printf("----------- %sEnqueue%s ------------\n", GRN, RESET);
                    printf("Enter value to enqueue: ");
                    while (scanf("%d", &value) != 1) {
                        printf("%sInvalid Input!%s", RED, RESET) ;
                        clearBuffer();
                        getchar();
                        clearScreen();
                        printf("----------- %sEnqueue%s ------------\n", GRN, RESET);
                        printf("Enter value to enqueue: ");
                    }
                    enqueue(queue, value);
                    printf("%sEnqueued %d into the queue.%s\n", GRN, value, RESET);
                }

                clearBuffer();
                getchar();
                break;

            case 2:
                value = dequeue(queue, &status);
                if (status)
                    printf("%sDequeued value: %d%s\n", GRN, value, RESET);
                else
                    printf("%sQueue is empty! Cannot dequeue.%s\n", RED, RESET);

                clearBuffer();
                getchar();
                break;

            case 3:
                value = qPeek(queue, &status);
                if (status)
                    printf("%sFront value: %d%s\n", GRN, value, RESET);
                else
                    printf("%sQueue is empty! No front value.%s\n", RED, RESET);

                clearBuffer();
                getchar();
                break;

            case 4:
                if (qIsEmpty(queue))
                    printf("%sQueue is empty.%s\n", RED, RESET);
                else
                    printf("%sQueue is not empty. Size: %d%s\n", GRN, size(queue), RESET);
                
                clearBuffer();
                getchar();
                break;

            case 5:
                if (qIsFull(queue))
                    printf("%sQueue is full.%s\n", RED, RESET);
                else
                    printf("%sQueue is not full. Space left: %d%s\n", GRN, queue->capacity - size(queue), RESET);

                clearBuffer();
                getchar();
                break;

            case 6:
            clearScreen();
            printf("----------- %sDisplay All Elements%s ------------\n", GRN, RESET);
            displayQueue(queue);
            clearBuffer();
            getchar();
            break;

            case 7:
                destroyQueue(queue);
                printf("%sQueue destroyed.%s\n", GRN, RESET);
                clearBuffer();
                getchar();
                return;

            default:
                printf("%sInvalid choice!%s\n", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}

// Function Definitions

Queue *createQueue(int capacity) 
{
    if (capacity <= 0) return NULL;
    Queue *queue = malloc(sizeof(Queue));
    if (queue == NULL) 
    {
        printf("Memory allocation failed!\n");
        getchar();
        return NULL;
    }

    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

int size(Queue *queue) 
{
    return queue->size;
}

bool qIsEmpty(Queue *queue) 
{
    return (queue->size == 0);
}

bool qIsFull(Queue *queue) 
{
    return (queue->size >= queue->capacity);
}

int qPeek(Queue *queue, bool *status) 
{
    if (qIsEmpty(queue)) {
        *status = false;
        return -1;
    }
    *status = true;
    return queue->head->value;
}

void enqueue(Queue *queue, int value) 
{
    if (qIsFull(queue)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    QueueNode *newNode = malloc(sizeof(QueueNode)); 
    if (!newNode) 
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = NULL;

    if (qIsEmpty(queue)) 
    {
        queue->head = newNode;
        queue->tail = newNode;
    } else 
    {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;
}

int dequeue(Queue *queue, bool *status) 
{
    if (qIsEmpty(queue)) {
        *status = false;
        return -1; 
    }

    *status = true;
    int value = queue->head->value;

    QueueNode *oldHead = queue->head;
    queue->head = queue->head->next;
    if (!queue->head) 
    {
        queue->tail = NULL;
    }
    free(oldHead);
    queue->size--;
    return value;
}

void destroyQueue(Queue *queue) 
{
    QueueNode *currentNode = queue->head;
    while (currentNode != NULL) 
    {
        QueueNode *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}


void displayQueue(Queue *queue) 
{
    if (qIsEmpty(queue)) 
    {
        printf("%sQueue is empty!%s\n", RED, RESET);
        return;
    }

    printf("Queue elements: ");
    QueueNode *current = queue->head;
    while (current != NULL) 
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}
