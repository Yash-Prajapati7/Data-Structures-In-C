#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *front, *rear;

void enqueue(int element) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = element;
    if(rear == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    rear->next = NULL;
}

int dequeue() {
    int val = -2;
    if(front == NULL) {
        return -1;
    }
    else if(front == rear) {
        val = front->data;
        front = NULL;
        rear = NULL;
    }
    else {
        val = front->data;
        front = front->next;
    }
    return val;
}

int peek() {
    if(front == NULL) {
        return -1;
    }
    else {
        return front->data;
    }
}

void display() {
    struct Node* temp = front;
    if(temp == NULL) {
        printf("Queue Empty\n");
    }
    else {
        while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void main() {
    int choice = 1, element, val;
    printf("Menu\n1 - Enqueue\n2 - Dequeue\n3 - Peek\n4 - Display\n5 - Exit\n");

    while(choice != 5 && choice > 0) {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
            printf("Enter a value : ");
            scanf("%d", &element);
            enqueue(element);
            break;

            case 2 :
            val = dequeue();
            if(val == -1) {
                printf("Queue Empty.\n");
            } else {
                printf("%d\n", val);
            }
            break;

            case 3 :
            val = peek();

            if(val == -1) {
                printf("Queue Empty.\n");
            }
            else {
                printf("%d\n", val);
            }

            break;

            case 4 :
            display();
            break;

            case 5 :
            printf("Exiting....");
            break;

            default :
            printf("Enter a valid choice.\n");
            break;
        }
    }
}