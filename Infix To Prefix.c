#include <stdio.h>
#define size 100
char s[size];
int l = 0;
int top = -1;

int isFull() { 
    return top == size - 1; 
}

int isEmpty() { 
    return top == -1; 
}

void push(char element) {
    if (isFull()) {
        printf("Stack Full");
        return;
    }
    s[++top] = element;
}

char pop() {
    if (isEmpty()) {
        return '\0'; // Return null character as an error value
    }
    return s[top--];
}

char peek() {
    if (isEmpty()) {
        return '\0'; // Return null character as an error value
    }
    return s[top];
}

void reverse(char arr[]) {
    int left = 0;
    int right = l - 1;
    while (left < right) {
        if (arr[left] == '(') {
            arr[left] = ')';
        } else if (arr[left] == ')') {
            arr[left] = '(';
        }
        if(arr[right] == '(') {
            arr[right] = ')';
        } else if (arr[right] == ')') {
            arr[right] = '(';
        }
        char temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int precedence(char character) {
    if (character == '(') {
        return 0;
    } else if (character == '+' || character == '-') {
        return 1;
    } else if(character == '*' || character == '/') {
        return 2;
    } else if(character == '^' || character == '%') {
        return 3;
    }
    return -1;
}

void infToPre(char infix[], char prefix[]) {
    reverse(infix);
    int i = 0, j = 0;
    char x;

    while((x = infix[i++]) != '\0') {
        if(x >= '0' && x <= '9') {
            prefix[j++] = x;
        } else if(x == '(') {
            push(x);
        } else if(x == ')') {
            while(!isEmpty() && peek() != '(') {
                prefix[j++] = pop();
            }
            pop();  // pop the '('
        } else {
            while(!isEmpty() && (precedence(x) <= precedence(peek()))) {
                prefix[j++] = pop();
            }
            push(x);
        }
    }

    while(!isEmpty()) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0';  // Null terminate the string
    reverse(prefix);
}

void length(char arr[]) {
     l = 0;
    while(arr[l] != '\0') {
        l++;
    }
}

int main() {
    char infix[size] = "1-9+2";
    char prefix[size];
    length(infix);      // Calculate the length of the infix expression
    infToPre(infix, prefix);
    printf("Prefix: %s", prefix);
    return 0;
}
