typedef struct DNode 
{
    int data;
    struct DNode *next;
    struct DNode *prev;
} DNode;


DNode *createDNode(int data)
{
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    
    return newNode;
}


void appendDNode(DNode **head, int data);
void traverseDList(DNode *head);
void insertDNodeAt(DNode **head, int data, int pos);
void deleteDNodeAt(DNode **head, int pos);
void bSortDList(DNode **head);
int searchDList(DNode *head, int value);
void mergeDList();
DNode *mergeDNode(DNode *head1, DNode *head2);
void doublySize(DNode *head, int *count);


void doublyLinkedList()
{
    DNode *head = NULL;
    int ch, value, pos;
    int count = 0;

    while(1)
    {
        clearScreen();
        printf("---- %sDoubly Linked List Menu%s ----\n", GRN, RESET);
        printf("[1] Add Node\n");
        printf("[2] Insert Node\n");
        printf("[3] Display Nodes\n");
        printf("[4] Delete Node\n");
        printf("[5] Sort Node\n");
        printf("[6] Search Node\n");
        printf("[7] Merge Node\n");
        printf("[8] Exit\n");
        printf("---------------------------------\n"); 
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
                        return;
                    }
                appendDNode(&head, value);
                printf("%s%d is successfully added to the list!%s\n", GRN, value, RESET);
                clearBuffer();
                getchar();
                break;

            case 2:
                printf("Enter value to insert: ");
                while (scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while (getchar() != '\n');
                    getchar();
                    return;
                }

                printf("Enter the position to insert at: ");
                while (scanf("%d", &pos) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while (getchar() != '\n');
                    getchar();
                    return;
                }

                insertDNodeAt(&head, value, pos);
                doublySize(head, &count);
                if(count > pos)
                    printf("%s%d is inserted at %d of the list!%s", GRN, value, pos, RESET);

                clearBuffer();
                getchar();
                break;

            case 3:
                traverseDList(head);
                getchar();
                break;

            case 4:
                printf("Enter the position of the node to delete: ");
                while (scanf("%d", &pos) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while (getchar() != '\n');
                    getchar();
                    return;
                }
                deleteDNodeAt(&head, pos);
                getchar();
                break;

            case 5:
                bSortDList(&head);
                break;

            case 6:
                printf("\nEnter value to search: ");
                while (scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input! Please enter an integer.%s\n", RED, RESET);
                    while (getchar() != '\n');
                    getchar();
                    return;
                }
                searchDList(head, value);
                getchar();
                getchar();
                break;

            case 7:
                mergeDList();
                break;

            case 8:
                return;

            default:
                printf("%sInvalid Input!%s", RED, RESET);
                getchar();
                break;

        }
    }
}


void appendDNode(DNode **head, int data)
{
    DNode *newNode = createDNode(data);
    if(*head == NULL)
        *head = newNode;
    else
    {
        DNode *temp = *head;
        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }
}


void traverseDList(DNode *head)
{
    if(head == NULL)
    {
        printf("%sThe list is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    printf("%sLinked List Nodes:%s\n", GRN, RESET);
    printf("NULL <- ");
    DNode *temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        if(temp->next != NULL)
            printf(" <-> ");

        temp = temp->next;
    }
    printf(" -> NULL\n");
}


void insertDNodeAt(DNode **head, int data, int pos)
{
    DNode *newNode = createDNode(data);

    if(pos <= 0)
    {
        printf("%sInvalid position! Position must start from 1.%s\n", RED, RESET);
        free(newNode);
        getchar();
        getchar();
        return;
    }

    if(pos == 1)
    {
        newNode->next = *head;
        if(*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DNode *temp = *head;

    for(int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
    {
        printf("%sPosition out of bounds! Adding to the end.%s\n", RED, RESET);
        appendDNode(head, data);
        free(newNode);
        getchar();
        return;
    }
    else
    {
        newNode->next = temp->next;
        if(temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
}


void deleteDNodeAt(DNode **head, int pos)
{
    if(*head == NULL)
    {
        printf("%sThe list is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    if(pos <= 0)
    {
        printf("%sInvalid Input! Positions must start from 1.%s\n", RED, RESET);
        getchar();
        return;
    }

    DNode *temp = *head;

    if(pos == 1)
    {
        *head = temp->next;
        if(*head != NULL)
            (*head)->prev = NULL;
        free(temp);
        printf("%sNode at position %d deleted successfully.%s\n", GRN, pos, RESET);
        getchar();
        getchar();
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
    {
        printf("%sPosition out of bounds!%s\n", RED, RESET);
        getchar();
        getchar();
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("%sNode at position %d deleted successfully.%s\n", GRN, pos, RESET);
    getchar();
}


void bSortDList(DNode **head)
{
    if(*head == NULL || (*head)->next == NULL)
    {
        printf("%sThe list is empty!%s\n", RED, RESET);
        getchar();
        return;
    }

    int swapped;
    DNode *current;
    DNode *lastSorted = NULL;

    do
    {
        swapped = 0;
        current = *head;

        while(current->next != lastSorted)
        {
            if(current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;

                swapped = 1;
            }
            current = current->next;
        }
        lastSorted = current;
    } while(swapped);

    printf("%sThe list has been sorted!%s\n", GRN, RESET);
    getchar();
}


int searchDList(DNode *head, int value)
{
    if(head == NULL)
    {
        printf("%sThe list is empty!%s\n", RED, RESET);
        getchar();
        return -1;
    }

    DNode *temp = head;
    int pos = 1;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("%sValue %d found at position %d.%s\n", GRN, value, pos, RESET);
            return pos;
        }
        temp = temp->next;
        pos++;
    }

    printf("%sValue %d not found in the list.%s\n", RED, value, RESET);
    return -1;
}


void mergeDList()
{
    DNode *list1 = NULL;
    DNode *list2 = NULL;

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
            appendDNode(&list1, value);
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
            appendDNode(&list2, value);
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
    traverseDList(list1);

    printf("\nList 2:\n");
    traverseDList(list2);

    DNode *mergedHead = mergeDNode(list1, list2);

    printf("\n%sMerge Sorted List%s\n", GRN, RESET);
    traverseDList(mergedHead);

    getchar();
}


DNode *mergeDNode(DNode *head1, DNode *head2)
{
    if (head1 == NULL) 
        return head2;
    if (head2 == NULL) 
        return head1; 

    DNode *mergedHead = NULL;

    if (head1->data <= head2->data) 
    {
        mergedHead = head1;
        head1 = head1->next;
    } 
    else 
    {
        mergedHead = head2;
        head2 = head2->next;
    }
    mergedHead->prev = NULL;

    DNode *current = mergedHead;

    while (head1 != NULL && head2 != NULL) 
    {
        if (head1->data <= head2->data) 
        {
            current->next = head1;
            head1->prev = current;
            head1 = head1->next;
        } 
        else 
        {
            current->next = head2;
            head2->prev = current;
            head2 = head2->next;
        }
        current = current->next;
    }

    if (head1 != NULL) 
    {
        current->next = head1;
        head1->prev = current;
    }
    if (head2 != NULL) 
    {
        current->next = head2;
        head2->prev = current;
    }

    return mergedHead;
}


void doublySize(DNode *head, int *count)
{
    DNode *temp = head;

    while(temp != NULL)
    {
        temp = temp->next;
        (*count)++;
    }
}