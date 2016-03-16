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
	if (head==NULL||K<=1)						//initial validity check
		return NULL;

	struct node *temp = head;
	while (temp != NULL){						//removing every Kth node until it reached to the end
		for (int i = 1; i < K - 1 && temp != NULL; i++){
			temp = temp->next;
		}
		if (temp != NULL&&temp->next != NULL){
			temp->next = temp->next->next;		//removing Kth node
			temp = temp->next;					//going to the next node
		}
	}
	return head;		//returning the head of the list
}