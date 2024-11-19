#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff, pow;
    struct Node *next;
} *head, *head1, *head2;

struct Node *add(struct Node *head1, struct Node *head2) {
    if(head1 == NULL) {
        return head2;
    }
    else if(head2 == NULL) {
        return head1;
    }

    // Create a dummy node
    head = (struct Node *) malloc(sizeof(struct Node));
    head->coeff = 0;
    head->pow = 0;
    head->next = NULL;

    struct Node *temp = head;

    while(head1 != NULL && head2 != NULL) {
        int coeff1 = head1->coeff, coeff2 = head2->coeff, pow1 = head1->pow, pow2 = head2->pow;
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

        if(pow1 > pow2) {
            newNode->coeff = coeff1;
            newNode->pow = pow1;
            head1 = head1->next;
        }
        else if(pow1 < pow2) {
            newNode->coeff = coeff2;
            newNode->pow = pow2;
            head2 = head2->next;
        }
        else {
            newNode->coeff = coeff1 + coeff2;
            newNode->pow = pow1;
            head1 = head1->next;
            head2 = head2->next;
        }

        newNode->next = NULL;
        temp->next = newNode;
        temp = temp->next;
    }

    if(head1 == NULL) {
        temp->next = head2;
    }
    else {
        temp->next = head1;
    }

    return head->next; // we can't return head since it is pointing to the dummy node we created
}

struct Node *sub(struct Node *head1, struct Node *head2) {
    struct Node *temp = head2;
    while(temp != NULL) {
        temp->coeff = -temp->coeff;
        temp = temp->next;
    }
    // Just change the sign of coeffecient of list2 from '+' to '-' and '-' to '+' and perform addition operation
    return add(head1, head2);
}

struct Node *create(struct Node *head) {
    struct Node *temp = NULL;
    int n = 0;
    printf("Enter the number of Nodes\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
        newNode->next = NULL;

        printf("Enter Coeffecient and Power of the node\n");
        scanf("%d", &(newNode->coeff)); // Corrected here
        scanf("%d", &(newNode->pow));   // Corrected here

        if(head == NULL) {
            head = newNode;
            temp = head; // Update temp after head assignment
        } else {
            temp->next = newNode; // Only add to next for non-first nodes
            temp = temp->next;    // Move temp to the new node
        }
    }

    return head;
}

void print(struct Node *head) {
    if(head == NULL) {
        printf("LinkedList Empty\n");
        return;
    }
    struct Node *temp = head;
    
    // Use a flag to check if the first term has been printed
    int firstTerm = 1;

    while(temp != NULL) {
        if (temp->coeff != 0) {
            if (!firstTerm && temp->coeff > 0) {
                printf(" + ");
            } else if (temp->coeff < 0) {
                printf(" - ");
            }

            // Print the absolute value of the coefficient
            if (abs(temp->coeff) != 1 || temp->pow == 0) {
                printf("%d", abs(temp->coeff));
            }
            
            // Print the x and power part
            if (temp->pow > 1) {
                printf("x^%d", temp->pow);
            } else if (temp->pow == 1) {
                printf("x");
            }

            firstTerm = 0;  // Mark that the first term has been printed
        }
        
        temp = temp->next;
    }
    
    printf("\n"); // New line at the end of output
}


int main() {
    head1 = create(head1);
    head2 = create(head2);
    head = add(head1, head2);
    
    print(head1);
    print(head2);
    
    printf("After Addition\n");
    print(head);

    head = sub(head1, head2);
    printf("After Subtraction\n");
    print(head);
    return 0;
}