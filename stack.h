
#include <stdbool.h>

typedef struct stack_node_st {
	int numerator; 
	int denominator; 
	struct stack_node_st *next;
} Stack_Node;

typedef struct stack_st {
	Stack_node *first; 
} Stack;

typedef struct tuple_st {
	int first;
	int second;
} Tuple;

void Stack_Init(Stack *s);

void Stack_Add(Stack *s, int num, int denom);

bool Stack_Pop(Stack *s); 

bool Stack_Contains(Stack *s);

void Print_Top(Stack *s);

Tuple* Stack_Peek(Stack *s);

void Stack_Clear(Stack *s);

void Stack_Print(Stack *s);