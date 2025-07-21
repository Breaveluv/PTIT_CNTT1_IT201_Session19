#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

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
}

void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data); // Bỏ \n để output đẹp hơn
    inorder(root->right);
}

typedef struct Queue {
    Node **arr;
    int capacity; // Đổi size thành capacity để rõ ràng hơn
    int front;
    int rear;
    int current_size; // Theo dõi số lượng phần tử hiện tại
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        perror("Failed to allocate queue structure");
        exit(EXIT_FAILURE);
    }
    queue->arr = (Node **)malloc(sizeof(Node *) * capacity);
    if (queue->arr == NULL) {
        perror("Failed to allocate queue array");
        free(queue);
        exit(EXIT_FAILURE);
    }
    queue->front = 0;
    queue->rear = -1; // rear = -1 biểu thị queue rỗng, phần tử đầu tiên sẽ ở rear = 0
    queue->capacity = capacity;
    queue->current_size = 0;
    return queue;
}

int isQueueEmpty(Queue *queue) {
    return queue->current_size == 0;
}

int isQueueFull(Queue *queue) {
    return queue->current_size == queue->capacity;
}

void enqueue(Queue *queue, Node *node) {
    if (isQueueFull(queue)) {
        printf("Queue is full\n");
    } else {
        queue->rear = (queue->rear + 1) % queue->capacity; // Xử lý vòng tròn
        queue->arr[queue->rear] = node;
        queue->current_size++;
    }
}

Node *dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        // printf("Queue is empty\n"); // Không nên in lỗi trong hàm dequeue khi nó có thể được dùng để kiểm tra rỗng
        return NULL;
    } else {
        Node *node = queue->arr[queue->front];
        queue->front = (queue->front + 1) % queue->capacity; // Xử lý vòng tròn
        queue->current_size--;
        return node;
    }
}

// Hàm giải phóng queue
void freeQueue(Queue *queue) {
    if (queue) {
        free(queue->arr);
        free(queue);
    }
}

// Hàm levelorderBFS đã sửa
void levelorderBFS(Node *root) {
    if (root == NULL) {
        return;
    }

    Queue *queue = createQueue(100); // Kích thước đủ lớn
    enqueue(queue, root);

    while (!isQueueEmpty(queue)) {
        Node *currentNode = dequeue(queue);
        printf("%d ", currentNode->data);

        if (currentNode->left != NULL) {
            enqueue(queue, currentNode->left);
        }
        if (currentNode->right != NULL) {
            enqueue(queue, currentNode->right);
        }
    }
    freeQueue(queue); // Giải phóng bộ nhớ của queue sau khi dùng xong
}

// Hàm giải phóng bộ nhớ của cây
void freeTree(Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node *root = NULL;
    root = createNode(1);
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

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Level-order BFS Traversal: ");
    levelorderBFS(root);
    printf("\n");

    freeTree(root); // Giải phóng bộ nhớ của cây
    return 0;
}