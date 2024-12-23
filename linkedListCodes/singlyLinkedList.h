typedef struct Node {
    int data;
    struct Node *next;
} Node;


Node* createNode(int data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}


void append(Node **head, int data);
void traverse(Node *head);
void insertAtPosition(Node **head, int data, int pos);
void deleteHead(Node **head);
void deleteAtPosition(Node **head, int pos);
int search(Node *head, int value);
void bSortLinkedList(Node *head);
void mergeLinkedList();
Node *mergeSortedLists(Node *head1, Node *head2);
void singlySize(Node *head, int *count);


void singlyLinkedList()
{
    Node *head = NULL;
    int ch, value, pos;
    int count = 0; 

    while(1) 
    {
        clearScreen();
        printf("---- %sSingly Linked List%s ----\n", GRN, RESET);
        printf("[1] Add Node\n");
        printf("[2] Insert Node\n");
        printf("[3] Traverse/Display List\n");
        printf("[4] Delete Node\n");
        printf("[5] Search Node\n");
        printf("[6] Sort Node\n");
        printf("[7] Merge Node\n");
        printf("[8] Exit\n");
        printf("------------------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        switch(ch)
        {
            case 1:
                printf("\nEnter value to add: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while(getchar() != '\n');
                    getchar();
                    getchar();
                    return;
                }
                append(&head, value);
                printf("%s%d is successfully added to the list!%s\n", GRN, value, RESET);
                clearBuffer();
                getchar();
                break;

            case 2:
                printf("Enter a value to insert: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while(getchar() != '\n');
                    getchar();
                    getchar();
                    return;
                }

                printf("Enter the position to insert at: ");
                while(scanf("%d", &pos) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while(getchar() != '\n');
                    getchar();
                    getchar();
                    return;
                }
                insertAtPosition(&head, value, pos);
                singlySize(head, &count);
                if(count > pos)
                    printf("%s%d is inserted at %d of the list!%s", GRN, value, pos, RESET);
                clearBuffer();
                getchar();
                break;


            case 3:
                traverse(head);
                getchar();
                break;

            case 4:
                printf("Enter position to delete: ");
                while(scanf("%d", &pos) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while(getchar() != '\n');
                    getchar();
                    return;
                }
                deleteAtPosition(&head, pos);
                getchar();
                break;

            case 5:
                printf("Enter value to search for: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while(getchar() != '\n');
                    getchar();
                    return;
                }

                pos = search(head, value);
                if(pos != -1) 
                    printf("%sValue %d found at position %d.%s\n", GRN, value, pos, RESET);
                else if(head != NULL)
                    printf("%sValue %d not found in the linked list.%s\n", RED, value, RESET);

                clearBuffer();
                getchar();
                break;

            case 6:
                bSortLinkedList(head);
                getchar();
                break;

            case 7:
                mergeLinkedList();
                break;

            case 8:
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                getchar();
                getchar();
                break;
        }
    }

    Node *temp;
    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}


void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if(*head == NULL)
        *head = newNode;
    else
    {
        Node *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}


void traverse(Node *head)
{
    Node *temp = head;
    if(head == NULL)
    {
        printf("\n%sThe list is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    printf("\n%sElements in the linked list:%s\n", GRN, RESET);
    while(temp != NULL)
    {
        printf(" %d ->", temp->data);
        temp = temp->next;
    }

    printf(" NULL\n");
    //getchar();
}


void insertAtPosition(Node **head, int data, int pos) {
    if (pos <= 0) { 
        printf("%sInvalid position! Positions must start from 1.%s\n", RED, RESET);
        getchar();
        return;
    }

    Node *newNode = createNode(data);
    if (newNode == NULL) {
        printf("%sMemory allocation failed!%s\n", RED, RESET);
        return;
    }

    if (pos == 1) { 
        newNode->next = *head;
        *head = newNode;
    } else {
        Node *temp = *head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL) { 
            printf("%sPosition out of bounds! Adding to the end.%s\n", RED, RESET);
            append(head, data);
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}


void deleteHead(Node **head)
{
    if (*head == NULL)
    {
        printf("%sList is empty!%s\n", RED, RESET);
        getchar();
        return;
    }


    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("%sDeleted Successfully!%s\n", GRN, RESET);
    getchar();
}


void deleteAtPosition(Node **head, int pos)
{
    if(*head == NULL)
    {
        printf("%sList is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    if(pos == 1)
    {
        deleteHead(head);
        return;
    }

    Node *temp = *head;
    for(int i  = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        printf("%sInvalid position!%s\n", RED, RESET);
        getchar();
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    printf("%sNode at position %d deleted.%s\n", GRN, pos, RESET);
    getchar();
}


int search(Node *head, int value)
{
    int pos = 1;
    Node *temp = head;

    if(temp == NULL)
    {
        printf("%sList is empty!%s\n", RED, RESET);
        getchar();
        return -1;
    }

    while(temp != NULL)
    {
        if(temp->data == value)
            return pos;

        temp = temp->next;
        pos++;
    }

    return -1;
}


void bSortLinkedList(Node *head)
{
    if(head == NULL)
    {
        printf("%sList is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    int swapped;
    Node *temp;

    do
    {
        swapped = 0;
        temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            if(temp->data > temp->next->data)
            {
                int tempData = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempData;

                swapped = 1;
            }

            temp = temp->next;
        }
    } while(swapped);

    printf("%sSorted Succesfully!%s", GRN, RESET);
    getchar();
}


void mergeLinkedList()
{
    Node *list1 = NULL;
    Node *list2 = NULL;

    int ch, value;

    while(1)
    {
        clearScreen();
        printf("-------- %sMerge Linked List%s -------\n", GRN, RESET);
        printf("[1] Add Elements to List %s1%s", BLU, RESET);
        printf("\n[2] Stop Adding to List %s1%s", BLU, RESET);
        printf("\n-------------------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        if(ch == 1)
        {
            printf("Enter value to add: ");
            while(scanf("%d", &value) != 1)
            {
                printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                while(getchar() != '\n');
                getchar();
                return;
            }
            append(&list1, value);
        }
        else if(ch == 2)
            break;
        else
        {
            printf("%sInvalid Input!%s", RED, RESET);
            getchar();
        }
    }

    while(1)
    {
        clearScreen();
        printf("-------- %sMerge Linked List%s -------\n", GRN, RESET);
        printf("[1] Add Elements to List %s2%s", BLU, RESET);
        printf("\n[2] Stop Adding to List %s2%s", BLU, RESET);
        printf("\n-------------------------------\n");
        printf("Response: ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        if(ch == 1)
        {
            printf("Enter value to add: ");
            while(scanf("%d", &value) != 1)
            {
                printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                while(getchar() != '\n');
                getchar();
                return;
            }
            append(&list2, value);
        }
        else if(ch == 2)
            break;
        else
        {
            printf("%sInvalid Input!%s", RED, RESET);
            getchar();
        }
    }

    printf("\nList 1:\n");
    traverse(list1);

    printf("\nList 2:\n");
    traverse(list2);

    Node *mergedList = mergeSortedLists(list1, list2);

    printf("\nMerge Sorted List\n");
    traverse(mergedList);

    getchar();
}


Node *mergeSortedLists(Node *head1, Node *head2)
{
    if(head1 == NULL)
        return head2;   
    if(head2 == NULL)
        return head1;

    Node *mergeHead = NULL;

    if(head1->data <= head2->data)
    {
        mergeHead = head1;
        head1 = head1->next;
    }
    else 
    {
        mergeHead = head2;
        head2 = head2->next;
    }

    Node *current = mergeHead;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data <= head2->data)
        {
            current->next = head1;
            head1 = head1->next;
        }
        else
        {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    if(head1 != NULL)
        current->next = head1;
    else if(head2 != NULL)
        current->next = head2;

    return mergeHead;
}


void singlySize(Node *head, int *count)
{
    Node *temp = head;

    while(temp != NULL)
    {
        temp = temp->next;
        (*count)++;
    }
}