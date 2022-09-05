
#include <stdio.h>   // for printf
#include <stdlib.h>  // for malloc, free, and EXIT_FAILURE
#include <string.h>
#include "stack.h"

void Stack_Init(Stack *s) {
	s -> first = NULL;
}

void Stack_Add(Stack *s, int num, int denom) {
	Stack_Node * node = malloc(sizeof(Stack_Node));

	if (node == NULL) {
		printf("Couldn't allocate space for a new Stack Node");
		exit(EXIT_FAILURE);
	}

	node -> next = s -> first;
	node -> numerator = num;
	node -> denominator = denom;

	s -> first = node; //add to top of stack

}

bool Stack_Pop(Stack *s) {


	if (!s -> first) {
		return false;
	}

	Stack_Node * next_first = s -> first -> next;

	free(s -> first);
	s -> first = next_first;

	return true;
}

bool Stack_Contains(Stack *s) {
	if (!s -> first) {
		return false;
	}
	return true;
}

void Print_Top(Stack *s) {

	int num = s -> first -> numerator;
	int denom = s -> first -> denominator;

	printf("%d/%d\n", num, denom);
}

Tuple* Stack_Peek(Stack *s) {
	Tuple * tup = malloc(sizeof(Tuple));
	tup -> first = s -> first -> numerator;
	tup -> second = s -> first -> denominator;
	return tup;
}

void Stack_Clear(Stack *s) {
	while (Stack_Contains(s)) {
		Stack_Pop(s);
	}
}

void Stack_Print(Stack *s) {
	Stack_Node *curr = s -> first;

	printf("\nSTACK CONTAINS\n");

	while(curr) {
		printf("%d/%d\n", curr -> numerator, curr -> denominator);
		curr = curr -> next;
	}
}








