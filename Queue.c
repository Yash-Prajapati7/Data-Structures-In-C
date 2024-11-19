#include<stdio.h>
#include<conio.h>
int q[100];
int rear = -1;

int isEmpty() {
    if(rear == -1) {
        return 1;
    }
    return 0;
}
int isFull() {
    if(rear == 100) {
        return 1;
    }
    return 0;
}
void shift() {
    if(!isEmpty()) {
        for(int i = 0; i < rear; i++) {
            q[i] = q[i + 1];
        }
    }
}
void add(int val) {
    if(!isFull()) {
        q[++rear] = val;
    }
}
int pop() {
    int val = -1;
    if(!isEmpty()) {
        val = q[0];
        shift();
        rear = rear - 1;
    }
    return val;
}
int peek() {
    if(!isEmpty()) {
        return q[0];
    }
    return -1;
    
}
void display() {
    if(!isEmpty()) {
        for(int i = 0; i <= rear; i++) {
            printf("%d   ", q[i]);
        }
        printf("\n");
    }
    else {
        printf("Queue Empty\n");
    }
}

void main() {
    printf("Menu :\n1 - Add\n2 - Pop\n3 - Peek\n4 - Display\n5 - Exit\n");
    int choice = 1;
    int element = 0;
    int val = 1;

    while(choice != 5 && choice > 0) {
        printf("Enter your choice\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1 :
            printf("Enter a value : ");
            scanf("%d", &element);
            add(element);
            break;

            case 2 :
            val = pop();
            if(val == -1) {
                printf("Queue Empty.\n");
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
            printf("Enter a valid choice.");
            break;
        }
    }
}