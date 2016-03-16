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
	if (N < 0){									//if the given no.is -ve
		N = -N;
	}
	struct node *head = NULL, *temp;
	if (N == 0){								//if N=0
		head = (struct node *)malloc(sizeof(struct node));
		head->num = 0;
		head->next = NULL;
	}
	else{										//converting N to list
		for (; N>0;){
			if (head == NULL){					//for first node
				head = (struct node *)malloc(sizeof(struct node));
				head->num = N % 10;
				head->next = NULL;
			}
			else{								//insertion first
				temp = (struct node *)malloc(sizeof(struct node));
				temp->num = N % 10;
				temp->next = head;
				head = temp;
			}
			N = N / 10;
		}
	}
	return head;
}