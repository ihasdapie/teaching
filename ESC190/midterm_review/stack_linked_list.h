#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 200

#ifndef SLL_H
#define SLL_H

/**
	Implements a stack data type using Linked Lists;
	the head of the LL is treated as the top of the
	stack
*/

typedef struct Person {
	int age;
	char name[MAX_NAME_LEN];
} Person;

typedef struct StackNode {
	Person* cargo;
	struct StackNode* next;
} StackNode;

typedef struct StackAsLinkedList {
	StackNode* top;
	int num_el;
} StackAsLinkedList;

/**
	Formatted printed output to stdout
*/
void print_person(Person* p){
	fprintf(stdout, "%s Age: %d", p->name, p->age);
}


void print_stack(StackAsLinkedList* s){
	fprintf(stdout, "\n\nNow printing stack with %d elements... \n", s->num_el);
	StackNode* curr = s->top;
	while(curr != NULL){
		if (curr == s->top){
			// color formatting: red for the top of the stack
			fprintf(stdout, "\033[0;31m");
			fprintf(stdout, "[");
			fprintf(stdout, "\033[0m");
			print_person(curr->cargo);
			fprintf(stdout, "\033[0;31m");
			fprintf(stdout, "] ---> TOP OF THE STACK\n");
			fprintf(stdout, "\033[0m");
		} else if (curr->next == NULL){
			// color formatting: green for the bottom of the stack
			fprintf(stdout, "\033[0;32m");
			fprintf(stdout, "[");
			fprintf(stdout, "\033[0m");
			print_person(curr->cargo);
			fprintf(stdout, "\033[0;32m");
			fprintf(stdout, "] ---> BOTTOM OF THE STACK\n");
			fprintf(stdout, "\033[0m");
		} else {
			// middle of the stack
			fprintf(stdout, " ");
			print_person(curr->cargo);
			fprintf(stdout, "\n");
		}
		curr = curr->next;
	}
}


/**
	Constructing needed structs (initializing)
*/
Person* person_from_info(char name[], int age){
	Person* p = (Person*)malloc(sizeof(Person));
	p->age = age;
	strcpy(p->name, name);
	return p;
}


StackAsLinkedList* initialize_stack(){
	/** is 
		Initialize an empty stack
		The stack has its top field NULL iff it
		is empty, with num_el set to 0
	*/
	StackAsLinkedList* new_stack = (StackAsLinkedList*)malloc(sizeof(StackAsLinkedList));
	new_stack->top = NULL;
	new_stack->num_el = 0;
	return new_stack;
}

/**
	Stack operations
*/
void push(StackAsLinkedList* s, Person* p){
	// 1. create a new node
	StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
	
	// 2. set the fields (cargo, next)
	new_node->cargo = p;
	new_node->next = s->top;
	
	//3.change s->top to reference the new node instead
	s->top = new_node;
	
	// 4. increment s->num_el
	s->num_el++;
}


Person* pop(StackAsLinkedList* s){
	/**
	Allowed to assume that I only call pop
	on a non-empty stack.
	*/
	
	Person* p = s->top->cargo;
	
	// bookkeeping
	StackNode* old_top = s->top;
	s->top = s->top->next;
	free(old_top);
	s->num_el--;
	return p;
}




#endif
