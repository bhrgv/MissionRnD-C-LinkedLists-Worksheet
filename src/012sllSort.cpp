/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head){
	struct node* curr = head;
	int c0 = 0, c1 = 0, c2 = 0;
	while (curr != NULL)
	{
		if (curr->data == 0)
			c0++;
		else if (curr->data == 1)
			c1++;
		else if (curr->data == 2)
			c2++;
		curr = curr->next;
	}
	int i = 0, j = 0, k = 0,index=0;
	curr = head;
	for (i = 0; i < 3; i++)
	{
		switch(i){
		case 0:
			j = 0;
			k = c0;
			break;
		case 1:
			j = 1;
			k = c1;
			break;
		case 2:
			j = 2;
			k = c2;
			break;
		}
		for (index = 0; index < k; index++)
		{
			curr->data = j;
			curr = curr->next;
		}
	}
}