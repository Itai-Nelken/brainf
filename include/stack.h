#include "common.h"

//initializes a new stack with the size 'size'.
stack *stack_init(size_t size);

//free()'s a stack
void stack_free(stack *s);

//returns 0 if stack is full, else -1.
int stack_full(stack *s);

//returns 0 if stack is empty, else -1.
int stack_empty(stack *s);

//returns 0 if push is succesful or prints error message and returns -1 if stack is full.
int stack_push(stack *s, int data);

//returns the value popped if succesful or prints error message and returns -1 if stack is empty.
int stack_pop(stack *s);

//returns the top value in the stack or prints error message and returns -1 if stack is empty.
int stack_peek(stack *s);
