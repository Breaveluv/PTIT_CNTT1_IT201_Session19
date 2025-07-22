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

int searchDFS(Node *root, int key) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == key) {
        return 1;
    }
    return searchDFS(root->left, key)||searchDFS(root->right,key);
}

int main () {
    Node *root = NULL;
    root = createNode(1);
    Node *node1=createNode(2);
    Node *node2=createNode(3);
    Node *node3=createNode(4);
    Node *node4=createNode(5);
    Node *node5=createNode(6);

    root->left=node1;
    root->right=node2;
    root->left->left=node3;
    root->left->right=node4;
    root->right->right=node5;
    preorder(root);
    printf("\n");
    int find;
    printf("Enter the element you want to search: ");
    scanf("%d", &find);
    if (searchDFS(root,find)==1) {
        printf("true");
    }else {
        printf("false");
    }



    return 0;
}