## C
```c
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node *prev, *next;
} *head;

struct Node *createNode(int val) {
	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode->data = val;
	newNode->prev = newNode->next = NULL;
	return newNode;
}

struct Node *createList(int n) {
	struct Node *head1 = NULL;
	struct Node *temp = head1;
	struct Node *nn = NULL;

	for(int i = 1; i <= n; i++) {
		if(head1 == NULL) {
			head1 = createNode(i);
			temp = head1;
		}
		else {
			nn = createNode(i);
			temp->next = nn;
			nn->prev = temp;
			temp = nn;
		}

	}

	return head1;
}

struct Node *insertAfter(struct Node *head, int ele, int val) {
	struct Node *nn = createNode(ele);
	struct Node *temp = head;

	while(temp != NULL && temp->data != val) {
		temp = temp->next;
	}

	if(temp == NULL) {
	    printf("\nNo such node exists\n");
		return head;
	}

	if(temp->next == NULL) {
		nn->prev = temp;
		temp->next = nn;
		return head;
	}

	temp->next->prev = nn;
	nn->prev = temp;
	temp->next = nn;

	return head;
}

void print(struct Node *head) {
	while(head != NULL) {
		printf("%d -> ", head->data);
		head = head->next;
	}
	printf("NULL");
}

int main()
{
	int n, val = 0, ele = 0;
	printf("Enter the number of nodes you want to add : ");
	scanf("%d", &n);

	head = createList(n);
	print(head);

	printf("\nEnter the value of the node you want to insert after & the value of the node : ");
	scanf("%d %d", &val, &ele);
	head = insertAfter(head, ele, val);
	print(head);


	return 0;
}
```
