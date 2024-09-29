#include<stdio.h>
#include<conio.h>
#define SIZE 2;
int q[2];
int front = -1, rear = -1;

int isFull() {
    return front == (rear + 1) % SIZE;
}

int isEmpty() {
    return front == -1;
}

void enqueue(int element) {
    if(isFull()) {
        printf("Queue Full\n");
    }
    else if(front == -1){
        front++;
        q[++rear] = element;
    }
    else {
        rear = (rear + 1) % SIZE;
        q[rear] = element;
    }
}

int dequeue() {
    int val;
    if(isEmpty()) {
        return -1;
    }
    else if(front == rear) {
        val = q[front];
        rear = -1;
        front = -1;
    }
    else {
        val = q[front];
        front = (front + 1) % SIZE;
    }
    return val;
}

void display() {
    if(isEmpty()) {
        printf("Queue Empty\n");
    }
    else {
        int i = front;
        while(i != rear) {
            printf("%d   ", q[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d   \n", q[i]);
    }
    
}

int peek() {
    int val = -1;
    if(isEmpty()) {
        val = -1;
    }
    else {
        val = q[front];
    }
    return val;
}

int main() {
    int choice = 1;
    int element = -1;
    int returnedVal = 0;
    printf("Menu\n1 - Add value\n2 - Remove value\n3 - Display\n4 - Peek\n5 - Exit\n");
    while (choice != 5 && choice > 0) {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1 :
            printf("Enter element : ");
            scanf("%d", &element);
            enqueue(element);
            break;

            case 2 :
            returnedVal = dequeue();
            if(returnedVal == -1) {
                printf("Queue Empty\n");
            }
            else {
                printf("%d\n", returnedVal);
            }
            break;

            case 3:
            display();
            break;

            case 4 :
            returnedVal = peek();
            if(returnedVal == -1) {
                printf("Queue Empty\n");
            }
            else {
                printf("%d\n", returnedVal);
            }
            break;
        }
    }
}