#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
} *top;

void push(int element) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = element;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if(top == NULL) {
        return -1;
    }
    int val = top->data;
    top = top->next;
    return val;
}

int peek() {
    if(top == NULL) {
        return -1;
    }
    int val = top->data;
    return val;
}

void display() {
    struct Node* temp = top;
    while(temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
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
            int val = pop();
            if(val == -1) {
                printf("Stack Empty\n");
            } else {
                printf("%d\n", val);
            }            
        }
        if(choice == 3) {
            int val = peek();
            if(val == -1) {
                printf("Stack Empty\n");
            } else {
                printf("%d\n", val);
            }   
        }
        if(choice == 4) {
            display();
        }
    }
}