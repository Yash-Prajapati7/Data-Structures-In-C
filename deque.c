#include<stdio.h>
#include<conio.h>
int SIZE = 5;
int dq[5];
int front = -1, rear = -1;

int isFull() {
    return front == (rear + 1) % SIZE;
}

int isEmpty() {
    return front == -1;
}

void pushBack(int element) {
    if(isFull()) {
        printf("Queue Full\n");
    }
    else if(front == -1){
        front = rear = 0;
        dq[rear] = element;
    }
    else {
        rear = (rear + 1) % SIZE;
        dq[rear] = element;
    }
}

void pushFront(int element) {
    if(isFull()) {
        printf("Queue Full\n");
    }
    else if(front == -1) {
        front = rear = 0;
        dq[front] = element;
    }
    else {
        front = (front + SIZE - 1) % SIZE;
        dq[front] = element;
    }
}

int popBack() {
    int val;
    if(isEmpty()) {
        return -1;
    }
    else if(front == rear) {
        val = dq[rear];
        rear = front = -1;
    }
    else {
        val = dq[rear];
        rear = (rear + SIZE - 1) % SIZE;
    }
    return val;
}

int popFront() {
    int val;
    if(isEmpty()) {
        return -1;
    }
    else if(front == rear) {
        val = dq[front];
        rear = front = -1;
    }
    else {
        val = dq[front];
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
            printf("%d   ", dq[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d   \n", dq[i]);
    }
}

int main() {
    int choice = 1;
    int element = -1;
    int returnedVal = 0;
    printf("Menu\n1 - Add from Front\n2 - Add from Back\n3 - Pop from Front\n4 - Pop from Back\n5 - Display\n6 - Exit\n");

    while(choice != 6 && choice > 0) {
        printf("Enter choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1 :
            printf("Enter element : ");
            scanf("%d", &element);
            pushFront(element);
            break;

            case 2 :
            printf("Enter element : ");
            scanf("%d", &element);
            pushBack(element);
            break;

            case 3 :
            returnedVal = popFront();
            if(returnedVal == -1) {
                printf("Queue Empty\n");
            }
            else {
                printf("%d\n", returnedVal);
            }
            break;

            case 4 :
            returnedVal = popBack();
            if(returnedVal == -1) {
                printf("Queue Empty\n");
            }
            else {
                printf("%d\n", returnedVal);
            }
            break;

            case 5:
            display();
            break;
        }
    }
}
