## C
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* copyTree(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node* newNode = createNode(root->data);
    if (newNode == NULL) {
        return NULL;
    }
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);
    return newNode;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Original tree (inorder traversal): ");
    inorderTraversal(root);
    printf("\n");

    struct Node* copiedTree = copyTree(root);

    printf("Copied tree (inorder traversal): ");
    inorderTraversal(copiedTree);
    printf("\n");

    return 0;
}
```
