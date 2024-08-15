#include<stdio.h>
#include<conio.h>

int size = 100;
int s[100];
int top = -1;

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(top == size - 1) {
        return 1;
    }
    return 0;
}

void push(int element) {
    if(!isFull()) {
        s[++top] = element;
    }
    else {
        printf("Stack Full\n");
    }
}

int pop() {
    if(!isEmpty()) {
        return s[top--];
    }
    else {
        return -1; // Stack is empty
    }
}

int peek() {
    if(!isEmpty()) {
        return s[top];
    }
    return -1;  // Stack is empty
}

void display() {
    if(isEmpty()) {
        printf("Stack Empty\n");
    } else {
        for(int i = top; i >= 0; i--) {
            printf("%d  ", s[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice = 1;
    int element = 0;
    int val = 0;

    printf("Menu :\n1 - Push\n2 - Pop\n3 - Peek\n4 - Display\n5 - Exit\n");

    while(choice != 5 && choice > 0) {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &element);
                push(element);
                printf("Element pushed\n");
                break;

            case 2:
                val = pop();
                if(val == -1) {
                    printf("Stack Empty.\n");
                } else {
                    printf("Popped element: %d\n", val);
                }
                break;

            case 3:
                val = peek();
                if(val == -1) {
                    printf("Stack Empty.\n");
                } else {
                    printf("Top element: %d\n", val);
                }
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting....\n");
                break;

            default:
                printf("Enter a valid choice.\n");
                break;
        }
    }
}
