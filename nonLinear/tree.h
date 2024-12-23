typedef struct TreeNode
{
    int data;
    struct TreeNode *right;
    struct TreeNode *left;
} TreeNode;

typedef struct TreeQueueNode
{
    TreeNode *treeNode;
    struct TreeQueueNode *next;
} TreeQueueNode;

typedef struct TreeQueue
{
    TreeQueueNode *front;
    TreeQueueNode *rear;
} TreeQueue;


TreeNode* createTreeNode(int data);
int insertNode(TreeNode** root, int data);
TreeNode* searchNode(TreeNode* root, int data);
void inorderTraversal(TreeNode* root);
void preorderTraversal(TreeNode* root);
void postorderTraversal(TreeNode* root);
TreeNode* deleteNode(TreeNode* root, int data);
TreeNode* findMin(TreeNode* root);
void clearTree(TreeNode* root);
void breadthFirstTraversal(TreeNode* root);

TreeQueue* createTreeQueue();
int isTreeQueueEmpty(TreeQueue *q);
void treeEnqueue(TreeQueue *q, TreeNode *node);
TreeNode* treeDequeue(TreeQueue *q);
void freeTreeQueue(TreeQueue *q);

void tree()
{
    TreeNode *root = NULL;
    int ch, value;
    TreeNode *result;

    while(1)
    {
        clearScreen();
        printf("-------- %sBinary Tree Operations%s --------\n", GRN, RESET);
        printf("[1] Insert Node\n");
        printf("[2] Search Node\n");
        printf("[3] In-order Traversal\n");
        printf("[4] Pre-order Traversal\n");
        printf("[5] Post-order Traversal\n");
        printf("[6] Breadth-First Traversal\n");
        printf("[7] Delete Node\n");
        printf("[8] Exit\n");
        printf("--------------------------------------\n");
        printf("Response: ");
        while(scanf("%d", &ch) != 1)
        {
            printf("%sInvalid Input!%s", RED, RESET);
            clearBuffer();
            getchar();
            clearScreen();
            printf("\n-------- %sBinary Tree Operations%s --------\n", GRN, RESET);
            printf("[1] Insert Node\n");
            printf("[2] Search Node\n");
            printf("[3] In-order Traversal\n");
            printf("[4] Pre-order Traversal\n");
            printf("[5] Post-order Traversal\n");
            printf("[6] Breadth-First Traversal\n");
            printf("[7] Delete Node\n");
            printf("[8] Exit\n");
            printf("--------------------------------------\n");
            printf("Response: ");
        }

        switch(ch)
        {
            case 1:
                clearScreen();
                printf("---------- %sInsert Element%s --------------\n", GRN, RESET);
                printf("Enter value to insert: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input!%s", RED, RESET);
                    clearBuffer();
                    getchar();
                    clearScreen();
                    printf("---------- %sInsert Element%s --------------\n", GRN, RESET);
                    printf("Enter value to insert: ");
                }
                if (insertNode(&root, value))
                    printf("%s%d is inserted in the tree!%s", GRN, value ,RESET);
                clearBuffer();
                getchar();
                break;

            case 2:
                clearScreen();
                printf("---------- %sSearch Element%s --------------\n", GRN, RESET);
                printf("Enter value to search: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input!%s", RED, RESET);
                    clearBuffer();
                    getchar();
                    clearScreen();
                    printf("---------- %sSearch Element%s --------------\n", GRN, RESET);
                    printf("Enter value to search: ");
                }
                result = searchNode(root, value);
                if(result != NULL)
                    printf("%sNode %d found in the tree.%s\n", GRN, value, RESET);
                else
                    printf("%sNode %d not found in the tree.%s\n", RED, value, RESET);

                clearBuffer();
                getchar();
                break;

            case 3:
                clearScreen();
                printf("----------%s In-order Transversal%s -------------\n", GRN, RESET);
                inorderTraversal(root);
                clearBuffer();
                getchar();
                break;

            case 4:
                clearScreen();
                printf("---------- %sPre-order Transversal%s -------------\n", GRN, RESET);
                preorderTraversal(root);
                clearBuffer();
                getchar();
                break;

            case 5:
                clearScreen();
                printf("----------%s Post-order Transversal%s -------------\n", GRN, RESET);
                postorderTraversal(root);
                clearBuffer();
                getchar();
                break;  

            case 6:
                clearScreen();
                printf("---------- %sBreadth-First Traversal%s --------------\n", GRN, RESET);
                breadthFirstTraversal(root);
                clearBuffer();
                getchar();
                break;

            case 7:
                clearScreen();
                printf("---------- %sDelete Element%s --------------\n", GRN, RESET);
                inorderTraversal(root);
                printf("\nEnter value to delete: ");
                while(scanf("%d", &value) != 1)
                {
                    printf("%sInvalid Input!%s", RED, RESET);
                    clearBuffer();
                    getchar();
                    clearScreen();
                    printf("---------- %sDelete Element%s --------------\n", GRN, RESET);
                    inorderTraversal(root);
                    printf("\nEnter value to delete: ");
                }
                
                if (searchNode(root, value) == NULL)
                    printf("%sNode %d not found in the tree.%s\n", RED, value, RESET);
                else
                {
                    root = deleteNode(root, value);
                    printf("%sNode %d deleted!%s\n", GRN, value, RESET);
                }
                
                clearBuffer();
                getchar();
                break;

            case 8:
                clearTree(root);
                return;


            default:
                printf("%sInvalid Input!%s", RED, RESET);
                clearBuffer();
                getchar();
                break;
        }
    }
}

TreeNode *createTreeNode(int data)
{
    TreeNode *newNode = malloc(sizeof(TreeNode));
    if(newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        getchar();
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int insertNode(TreeNode **root, int data)
{
    if (*root == NULL) 
    {
        *root = createTreeNode(data);
        return 1;
    }

    if (data < (*root)->data) 
        return insertNode(&(*root)->left, data); 
    else if (data > (*root)->data) 
        return insertNode(&(*root)->right, data);
    else 
    {
        printf("%sDuplicate Value! Node not inserted.%s\n", RED, RESET);
        return 0;
    }
}

TreeNode *searchNode(TreeNode *root, int data)
{
    if(root == NULL || root->data == data)
        return root;

    if(data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

void inorderTraversal(TreeNode *root)
{
    if(root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(TreeNode *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(TreeNode *root)
{
    if(root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

TreeNode *findMin(TreeNode *root)
{
    while(root && root->left != NULL)
        root = root->left;

    return root;
}

TreeNode *deleteNode(TreeNode *root, int data)
{
    if (root == NULL) return root;

    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        // if node has no children
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // if node has one children
        if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        // if node has two children
        TreeNode *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void clearTree(TreeNode *root)
{
    if(root != NULL)
    {
        clearTree(root->left);
        clearTree(root->right);
        free(root);
    }
}

void breadthFirstTraversal(TreeNode* root)
{
    if (root == NULL)
        return;

    TreeQueue* q = createTreeQueue();
    treeEnqueue(q, root);

    while (!isTreeQueueEmpty(q)) {
        TreeNode* node = treeDequeue(q);
        printf("%d ", node->data);

        if (node->left != NULL)
            treeEnqueue(q, node->left);
        if (node->right != NULL)
            treeEnqueue(q, node->right);
    }

    freeTreeQueue(q);
}

TreeQueue* createTreeQueue()
{
    TreeQueue* q = malloc(sizeof(TreeQueue));
    q->front = q->rear = NULL;
    return q;
}


int isTreeQueueEmpty(TreeQueue *q)
{
    return (q->front == NULL);
}


void treeEnqueue(TreeQueue *q, TreeNode *node)
{
    TreeQueueNode* newNode = malloc(sizeof(TreeQueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}


TreeNode* treeDequeue(TreeQueue *q)
{
    if (isTreeQueueEmpty(q))
        return NULL;

    TreeQueueNode* temp = q->front;
    TreeNode* node = temp->treeNode;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}


void freeTreeQueue(TreeQueue *q)
{
    while (!isTreeQueueEmpty(q)) {
        treeDequeue(q);
    }
    free(q);
}
