/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	if (head==NULL)
		return NULL;
	struct node start;
	start.next = NULL;
	struct node* curr;
	while (head != NULL)
	{
		curr = &start;
		while (curr->next != NULL)
		{
			if (curr->next->num > head->num)
				break;
			curr = curr->next;
		}
		struct node* temp = head;
		head = temp->next;
		temp->next = curr->next;
		curr->next = temp;
	}
	return start.next;
}