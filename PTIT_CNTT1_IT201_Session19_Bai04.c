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
void inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d \n ", root->data);
    inorder(root->right);
    return;
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

    inorder(root);
    return 0;
}