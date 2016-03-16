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
	struct node *h1, *h2,*min;
	int temp;
	
	for (h1 = head; h1 != NULL; h1 = h1->next){
		min = h1;
		for (h2 = h1->next; h2 != NULL; h2 = h2->next){
			if (min->num > h2->num){					//finding the min position
				min = h2;
			}
		}
		if (h1 != min){									//swaping
			temp = h1->num;
			h1->num = min->num;
			min->num = temp;
		}
	}
	return head;										//returning the head
}