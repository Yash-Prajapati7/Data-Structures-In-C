#include<stdio.h>
#include<conio.h>
#include<math.h>

#define SIZE 100

float stack[SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == SIZE - 1;
}

void push(float element) {
    if (!isFull()) {
        stack[++top] = element;
    } else {
        printf("Stack Full\n");
    }
}

float pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        return -1; // Error value
    }
}


float evaluate(char postfix[SIZE]) {
    int i = 0;
    float result = 0.0;
    while(postfix[i] != '\0') {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i] - '0');
        }
        else {
            char operator = postfix[i];
            float operand1, operand2;
            operand2 = pop();
            operand1  = pop();
            switch(operator) {
                case '+' :
                result = (operand1 + operand2);
                break;

                case '-' :
                result = (operand1 - operand2);
                break;

                case '*' :
                result = (operand1 * operand2);
                break;

                case '/' :
                result = (operand1 / operand2);
                break;

                case '%' :
                result = ((int)operand1 % (int)operand2);
                break;

                case '^' :
                result = pow(operand1, operand2);
                break;
            }
            push(result);
        }
        i++;      
    }

    return result;
}

int main() {
    char postfix[100] = "35+27/8*-";
    printf("%f", evaluate(postfix));
}
