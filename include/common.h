#pragma once

#ifndef MEM_SIZE
#define MEM_SIZE 30000
#endif

#ifndef STACK_SIZE
#define STACK_SIZE 100
#endif

enum {
	OP_INC_P,
	OP_DEC_P,
	OP_INC_VAL,
	OP_DEC_VAL,
	OP_OUT,
	OP_IN,
	OP_JMP_FWD,
	OP_JMP_BCK,
	OP_END
};

typedef struct stack_s {
	int *data;
	int sp;
	size_t max_size;
} stack;

typedef struct mem_s {
	char *data;
	int ptr;
} mem;
