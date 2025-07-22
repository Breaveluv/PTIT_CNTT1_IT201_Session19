#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node *createNode(int data) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
    return;
}

// int searchDFS(Node *root, int key) {
//     if (root == NULL) {
//         return 0;
//     }
//     if (root->data == key) {
//         return 1;
//     }
//     return searchDFS(root->left, key)||searchDFS(root->right,key);
// }
typedef struct QueueNode {
    Node *treeNode;
    struct QueueNode *next;
}QueueNode;
typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
}Queue;
Queue *createQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
void enqueue(Queue *queue, Node *node) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    }else {
        queue->rear->next = newNode;
        queue->rear =newNode;

    }
}
Node *dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    Node *treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}
int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}
void addNode(Node *root, int addIndex) {
    if (root == NULL) {
        return;
    }
    Queue *q=createQueue();
    enqueue(q,root);
    while (!isQueueEmpty(q)) {
        Node *currentNode = dequeue(q);
        if (currentNode->left == NULL) {
            currentNode->left =createNode(addIndex);
            break;
        }else {
            enqueue(q,currentNode->left);
        }
        if (currentNode->right == NULL) {
            currentNode->right =createNode(addIndex);
            break;
        }else {
            enqueue(q,currentNode->right);
        }
    }

}
void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    Queue *q = createQueue();
    enqueue(q,root);
    while (!isQueueEmpty(q)) {
        Node *currentNode = dequeue(q);
        printf("%d ",currentNode->data);
        if (currentNode->left != NULL) {
            enqueue(q,currentNode->left);
        }
        if (currentNode->right != NULL) {
            enqueue(q,currentNode->right);
        }
    }
}
int main () {
    Node *root = createNode(1);
    Node *node1 = createNode(2);
    Node *node2 = createNode(3);
    Node *node3 = createNode(4);
    Node *node4 = createNode(5);
    Node *node5 = createNode(6);

    root->left = node1;
    root->right = node2;
    root->left->left = node3;
    root->left->right = node4;
    root->right->right = node5;
    preorder(root);
    printf("\n");
    int addIndex;
    printf("Enter index : ");
    scanf("%d", &addIndex);
    addNode(root,addIndex);
    printf("\n");
    printTree(root);



    return 0;
}