/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (K==1||K<0||head==NULL||K==0)
		return NULL;
	int i = 0;
	int j = K - 1;
	struct node start;
	start.next = head;
	struct node* curr = &start;
	while (curr->next != NULL)
	{
		if (i == j)
		{
			curr -> next = curr->next->next;
			i = (i + 1) % K;
		}
		i = (i + 1) % K;
		if (curr->next!=NULL)
		curr = curr->next;
	}
	return head;
}