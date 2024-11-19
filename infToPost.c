#include <stdio.h>
#include <conio.h>
#include <math.h>

#define SIZE 100

// Stack for characters (used in infix to postfix conversion)
char charStack[SIZE];
int charTop = -1;

// Stack for numbers (used in postfix evaluation)
float numStack[SIZE];
int numTop = -1;

// Utility functions for character stack
int isCharEmpty() {
    return charTop == -1;
}

int isCharFull() {
    return charTop == SIZE - 1;
}

void charPush(char element) {
    if (!isCharFull()) {
        charStack[++charTop] = element;
    } else {
        printf("Character Stack Full\n");
    }
}

char charPop() {
    if (!isCharEmpty()) {
        return charStack[charTop--];
    } else {
        return -1; // Error value
    }
}

char charPeek() {
    if (!isCharEmpty()) {
        return charStack[charTop];
    } else {
        return -1; // Error value
    }
}

// Utility functions for number stack
int isNumEmpty() {
    return numTop == -1;
}

int isNumFull() {
    return numTop == SIZE - 1;
}

void numPush(float element) {
    if (!isNumFull()) {
        numStack[++numTop] = element;
    } else {
        printf("Number Stack Full\n");
    }
}

float numPop() {
    if (!isNumEmpty()) {
        return numStack[numTop--];
    } else {
        return -1; // Error value
    }
}

// Function to check precedence of operators
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

// Function to convert infix to postfix expression
void infixToPostfix(const char* infix, char* postfix) {
    int i = 0, j = 0;
    char x;
    
    while ((x = infix[i++]) != '\0') {
        if (x >= '0' && x <= '9') {
            postfix[j++] = x;
        } else if (x == '(') {
            charPush(x);
        } else if (x == ')') {
            while (!isCharEmpty() && charPeek() != '(') {
                postfix[j++] = charPop();
            }
            if (!isCharEmpty() && charPeek() == '(') {
                charPop(); // Remove '(' from stack
            }
        } else {
            while (!isCharEmpty() && precedence(charPeek()) >= precedence(x)) {
                postfix[j++] = charPop();
            }
            charPush(x);
        }
    }
    
    // Pop remaining operators
    while (!isCharEmpty()) {
        postfix[j++] = charPop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

// Function to evaluate a postfix expression
float evaluate(const char* postfix) {
    int i = 0;
    float result = 0.0;
    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            numPush(postfix[i] - '0');
        } else {
            char operator = postfix[i];
            float operand1, operand2;
            operand2 = numPop();
            operand1 = numPop();
            switch (operator) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '%':
                    result = (int)operand1 % (int)operand2;
                    break;
                case '^':
                    result = pow(operand1, operand2);
                    break;
            }
            numPush(result);
        }
        i++;
    }

    return numPop();
}

int main() {
    char infix[SIZE];
    char postfix[SIZE];
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Convert Infix to Postfix and Evaluate\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                break;
            case 2:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix Expression: %s\n", postfix);
                printf("Evaluation Result: %.2f\n", evaluate(postfix));
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
