#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *head;

void insert(int element) {
    struct Node *newNode;
    newNode = (struct Node *) malloc(sizeof(struct Node));

    if (head == NULL) {
        newNode->data = element;
        newNode->next = NULL;
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newNode->data = element;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void insertBefore(int value, int element) {
    struct Node *newNode, *temp = head, *prev = NULL;

    newNode = (struct Node *) malloc(sizeof(struct Node));
    newNode->data = element;

    if (head != NULL && head->data == value) {
        newNode->next = head;
        head = newNode;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        newNode->next = temp;
        if (prev != NULL) {
            prev->next = newNode;
        }
    } else {
        printf("Value %d not found in the list.\n", value);
        free(newNode);
    }
}

void insertAfter(int value, int element) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp != NULL) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->data = element;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

void deleteByValue(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head != NULL && head->data == value) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Value %d not found in the list.\n", value);
    }
}

void deleteByIndex(int index) {
    struct Node *temp = head, *prev = NULL;
    int i = 0;

    if (index == 0 && head != NULL) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && i < index) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Index %d is out of bounds.\n", index);
    }
}

void print() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice = 1, element = 0, value = 0, index = 0;

    printf("Menu:\n");
    printf("1 - Insert Node at End\n");
    printf("2 - Insert Node Before a Value\n");
    printf("3 - Insert Node After a Value\n");
    printf("4 - Delete Node by Value\n");
    printf("5 - Delete Node by Index\n");
    printf("6 - Print List\n");
    printf("7 - Exit\n");

    while (choice != 7 && choice > 0) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                insert(element);
                break;

            case 2:
                printf("Enter value before which to insert: ");
                scanf("%d", &value);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertBefore(value, element);
                break;

            case 3:
                printf("Enter value after which to insert: ");
                scanf("%d", &value);
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insertAfter(value, element);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 5:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteByIndex(index);
                break;

            case 6:
                print();
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}