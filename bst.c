#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};

// Function to create a new TreeNode
struct TreeNode *createNode(int data) {
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to search and return the parent of a node or the closest node if not found
struct TreeNode *search(struct TreeNode *root, int val) {
    struct TreeNode *parent = NULL;
    while (root != NULL) {
        if (root->data == val) {
            break;
        }
        parent = root;
        if (root->data > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return parent;  // Returns the parent of the target node or the nearest node if not found
}

// Function to insert a new node using the search function
struct TreeNode *insert(struct TreeNode *root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    // Use the search function to find the parent where the new node should be attached
    struct TreeNode *parent = search(root, val);
    struct TreeNode *newNode = createNode(val);

    if (parent->data > val) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

// Function to find the maximum value node in a tree
struct TreeNode *returnMax(struct TreeNode *root) {
    if (root == NULL) return NULL;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

// Helper function for deleting a node
struct TreeNode *helper(struct TreeNode *root) {
    if (root->left == NULL) return root->right;
    else if (root->right == NULL) return root->left;
    else {
        struct TreeNode *newRoot = root->left;
        struct TreeNode *max = returnMax(newRoot);
        max->right = root->right;
        return newRoot;
    }
}

// Function to delete a node using the search function
struct TreeNode *deleteNode(struct TreeNode *root, int val) {
    if (root == NULL) return NULL;

    // Use the search function to locate the parent of the node to be deleted
    struct TreeNode *parent = search(root, val);
    struct TreeNode *target = NULL;

    // Determine if the node to delete is on the left or right of the parent
    if (parent->left != NULL && parent->left->data == val) {
        target = parent->left;
    } else if (parent->right != NULL && parent->right->data == val) {
        target = parent->right;
    } else {
        printf("Value %d not found in the tree.\n", val);
        return root;
    }

    // Use helper function to adjust the tree after deletion
    if (parent->left == target) {
        parent->left = helper(target);
    } else {
        parent->right = helper(target);
    }

    return root;
}

// Function for in-order traversal
void inorder(struct TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

int main() {
    struct TreeNode *root = NULL;
    int choice, value;

    printf("\nBinary Search Tree Operations:");
    printf("\n1. Insert Node");
    printf("\n2. Delete Node");
    printf("\n3. Search Node");
    printf("\n4. Display Inorder");
    printf("\n5. Exit");

    do {
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                if (search(root, value) != NULL && root != NULL && search(root, value)->data == value) {
                    printf("Value %d already exists in the tree.\n", value);
                } else {
                    root = insert(root, value);
                    printf("Value %d inserted successfully.\n", value);
                }
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Value %d deleted successfully (if existed).\n", value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                struct TreeNode *foundNode = search(root, value);
                if (foundNode != NULL && foundNode->data == value) {
                    printf("Value %d found in the tree.\n", value);
                } else {
                    printf("Value %d not found in the tree.\n", value);
                }
                break;
            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 5);

    getch();
    return 0;
}
