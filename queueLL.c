#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front = NULL, *rear = NULL;

void enqueue(int element) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = element;
    if (rear == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = NULL;
}

int dequeue() {
    int val = -2;
    if (front == NULL) {
        return -1;
    } else if (front == rear) {
        val = front->data;
        front = NULL;
        rear = NULL;
    } else {
        val = front->data;
        front = front->next;
    }
    return val;
}

int peek() {
    if (front == NULL) {
        return -1;
    }
    return front->data;
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue Empty\n");
    } else {
        while (temp != NULL) {
            printf("%d  ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    
    do {
        printf("\n--- Queue Operations ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            
            case 2:
                value = dequeue();
                if (value == -1) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    printf("Dequeued value: %d\n", value);
                }
                break;

            case 3:
                value = peek();
                if (value == -1) {
                    printf("Queue is empty. No element to peek.\n");
                } else {
                    printf("Front element is: %d\n", value);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
