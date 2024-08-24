#include <stdio.h>
#include <conio.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == SIZE - 1;
}

void push(char element) {
    if (!isFull()) {
        stack[++top] = element;
    } else {
        printf("Stack Full\n");
    }
}

char pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        return -1; // Error value
    }
}

char peek() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        return -1; // Error value
    }
}

int precedence(char op) {
    switch (op) {
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        case '^':
        case '%': return 4;
        default: return -1;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;
    
    while ((x = infix[i++]) != '\0') {
        if (x >= '0' && x <= '9') {
            postfix[j++] = x;
        } else if (x == '(') {
            push(x);
        } else if (x == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!isEmpty() && peek() == '(') {
                pop(); // Remove '(' from stack
            }
        } else {
            while (!isEmpty() && precedence(peek()) >= precedence(x)) {
                postfix[j++] = pop();
            }
            push(x);
        }
    }
    
    // Pop remaining operators
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[SIZE] = "3+5-2/7*8"; // Example infix expression
    char postfix[SIZE];
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}
