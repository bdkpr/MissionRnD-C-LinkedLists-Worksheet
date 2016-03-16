/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};

int convert_sll_2digit_to_int(struct node *head){
	if (head==NULL)													//validity
		return 0;
	int res=0, num_frm_node;
	for (; head != NULL; head = head->next){
		if (head->digit1 >= 0 && head->digit2 >= 0){
			num_frm_node = (head->digit1 * 10) + (head->digit2);	//extracting the number from the node
			res = res * 100 + num_frm_node;							//storing in thr result.
		}
		else{
			return 0;
		}
	}
	return res;												//returning the result.
}
