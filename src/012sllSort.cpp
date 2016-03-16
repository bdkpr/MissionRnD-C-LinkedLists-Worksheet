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
	if (head != NULL){					//validity checking
		int no_1s, no_2s, sum,n,no_0s;
		struct node *temp;
		temp = head;
		for (n=0,no_1s = 0, sum = 0; temp != NULL; temp = temp->next,n++){		//finding the no of 1's and the sum of all elements 
			if (temp->data <= 2 && temp->data >= 0){
				sum += temp->data;
				if (temp->data == 1){
					no_1s++;
				}
			}
			else{						//unwanted data occured
				break;
			}
		}
		if (temp == NULL&&sum>0){
			no_2s = (sum - no_1s) / 2;		//finding no of 2's 
			no_0s = n - (no_1s + no_2s);	//no of 1's
			temp = head;
			for (int i=0; (temp != NULL); temp = temp->next,i++){		//placing the 0's,1's and 2's 
				if (i<no_0s){
					temp->data = 0;
				}
				else if (i<no_0s + no_1s){
					temp->data = 1;
				}
				else{
					temp->data = 2;
				}
			}
		}
	}
}