// ESC190 Course Material. Copying, redistribution, or publishing strictly prohibited 
// without prior consent


#include <stdio.h>
#include <stdlib.h>

#ifndef LL_H

#define LL_H

typedef struct ListNode {
	int cargo;
	struct ListNode* next; // Q for the class: why not just an actual ListNode?
} ListNode;

ListNode* create_ll(int* arr, int n){
	/**
		arr is an arry representing the sequence of elements
		to construct a list from; it has n elements
	*/
	
	ListNode* head = (ListNode*)malloc(sizeof(ListNode)); 
	// I'm making it dynamic, static duration does not persist globally
	
	head->cargo = arr[0];
	head->next = NULL;
	
	ListNode* prev = head;
	ListNode* curr = NULL;
	for (int i=1; i < n; i++){
		curr = (ListNode*)malloc(sizeof(ListNode));
		curr->cargo = arr[i];
		curr->next = NULL;
		
		prev->next = curr;
		prev = curr;
	}

	return head;
}

void insert(ListNode* head, int idx, int val){
	ListNode* curr = head;
	ListNode* prev = NULL;
	
	for (int i=0; i < idx; i++){
		prev = curr;
		curr = curr->next;
	}
	
	ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
	new_node->cargo = val;
	new_node->next = curr;
	prev->next = new_node;
}

void print_ll(ListNode* head){
	ListNode* curr = head;
	while(curr != NULL){
		fprintf(stdout, "%d ", curr->cargo);
		curr = curr->next;
	} fprintf(stdout, "\n");
}

void delete_ll(ListNode** head){
	ListNode* curr = *head;
	ListNode* prev = *head;
	
	while(curr->next != NULL){
		curr = curr->next;
		free(prev);
		prev = curr;
	}
	free(curr);
	*head = NULL;
}



#endif
