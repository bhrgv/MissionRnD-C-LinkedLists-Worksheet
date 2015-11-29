/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	if (N == 0)
	{
		head->num = 0;
		return head;
	}
	if (N < 0)
		N *= -1;
	while (N)
	{
		int d = N % 10;
		struct node* element = (struct node*)malloc(sizeof(struct node));
		element->num = d;
		element->next = '\0';
		N /= 10;
		struct node* temp;
		temp = head->next;
		head->next = element;
		element->next = temp;
	}
	return head->next;
}