#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"

stack *stack_init(size_t size) {
	stack *s=malloc(sizeof(stack));
	s->data=calloc(size*sizeof(int *), sizeof(int));
	s->sp=0;
	s->max_size=size;
	return s;
}

void stack_free(stack *s) {
	free(s->data);
	free(s);
}

int stack_full(stack *s) {
	return s->sp==s->max_size ? 0 : -1;
}

int stack_empty(stack *s) {
	return s->sp<0 ? 0 : -1;
}

int stack_push(stack *s, int data) {
	s->sp++;
	if(stack_full(s)==0) {
		fprintf(stderr, "stack_push(): failed to push \"%d\": stack is full!\n", data);
		return -1;
	}
	s->data[s->sp]=data;
	return 0;
}

int stack_pop(stack *s) {
	if(stack_empty(s)==0) {
		fprintf(stderr, "stack_pop(): failed to pop: stack is empty!\n");
		return -1;
	}
	s->sp--;
	return s->data[s->sp+1];
}

int stack_peek(stack *s) {
	if(stack_empty(s)==0) {
		fprintf(stderr, "stack_peek(): failed to peek: stack is empty!\n");
		return -1;
	}
	return s->data[s->sp];
}
