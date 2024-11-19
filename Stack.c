#include<stdio.h>
#include<conio.h>
int size = 100;
int s[100];
int top = -1;
int val = 0;

int isEmpty() {
    if(top == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if(top == size) {
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
    if(!isEmpty(top)) {
        val = s[top--];
    }
    else {
        val = -1;
    }
    return val;
}

int peek() {
    if(!isEmpty(top)) {
        val = s[top];
    }
    else {
        val = -1;
    }
    return val;
}

void display() {
    if(isEmpty()) {
        printf("Stack Empty\n");
    }
    for(int i = top; i >= 0; i--) {
        printf("%d  ", s[i]);
    }
    printf("\n");
}

int main() {
    int choice = 1;
    int element = 0;
    printf("Menu :\n1 - push\n2 - pop\n3 - peek\n4 - display\n5 - exit\n");
    

    while(choice != 5 && choice > 0) {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("Enter the element : ");
            scanf("%d", &element);
            push(element);
            printf("Element pushed\n");
        }
        if(choice == 2) {
            printf("%d\n", pop());
        }
        if(choice == 3) {
            printf("%d\n", peek());
        }
        if(choice == 4) {
            display();
        }
    }
    getch();
}