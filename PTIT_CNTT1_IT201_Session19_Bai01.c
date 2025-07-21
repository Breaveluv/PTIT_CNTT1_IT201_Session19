#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode() {
    int value;
    scanf("%d", &value);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* myNode = createNode();

    printf("node = {\n");
    printf("    data: %d,\n", myNode->data);
    printf("    left->NULL,\n");
    printf("    right->NULL\n");
    printf("}\n");

    free(myNode);
    myNode = NULL;

    return 0;
}