## C
```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with a given value
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the binary tree
struct Node* insert(struct Node* root, int data) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recursively insert the new node
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

// Function to create a binary tree from user input
struct Node* createTree() {
    int data;
    struct Node* root = NULL;

    printf("Enter data for the root node (-1 to stop): ");
    scanf("%d", &data);

    // Create the root node
    if (data != -1) {
        root = createNode(data);
    }

    while (1) {
        printf("Enter data to insert (-1 to stop): ");
        scanf("%d", &data);
        
        if (data == -1) {
            break;
        }
        
        // Insert new node into the binary tree
        root = insert(root, data);
    }

    return root;
}

// Helper function to print the binary tree (Inorder Traversal)
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = createTree();
    
    printf("Inorder Traversal of the Binary Tree: ");
    inorderTraversal(root);
    
    return 0;
}
```
