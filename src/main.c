#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "stack.h"

#define MEM_SIZE 30000

int *prog;

mem *mem_init(size_t size) {
	mem *m=malloc(sizeof(mem));
	m->data=malloc(size*sizeof(char));
	m->ptr=0;
	for(int i=0; i<size; i++) {
		m->data[i]=0;
	}
	return m;
}

void mem_free(mem *m) {
	free(m->data);
	free(m);
}

int parse(char *str) {
	int pc=0;
	prog=malloc(strlen(str)*sizeof(int)+1);
	for(int i=0; i<strlen(str); i++) {
		switch(str[i]) {
			case '>':
				prog[pc]=OP_INC_P;
				break;
			case '<':
				prog[pc]=OP_DEC_P;
				break;
			case '+':
				prog[pc]=OP_INC_VAL;
				break;
			case '-':
				prog[pc]=OP_DEC_VAL;
				break;
			case '.':
				prog[pc]=OP_OUT;
				break;
			case ',':
				prog[pc]=OP_IN;
				break;
			case '[':
				prog[pc]=OP_JMP_FWD;
				break;
			case ']':
				prog[pc]=OP_JMP_BCK;
				break;
			default:
				fprintf(stderr, "ERROR: invalid instruction \"%c\"!\n", str[pc]);
				return 1;
		}
		pc++;
	}
	prog[pc]=OP_END;
	return 0;
}

void rm_chars_from_str(char* str, char c) {
    char *pr=str, *pw=str;
    while (*pr) {
        *pw=*pr++;
        pw+=(*pw != c);
    }
    *pw = '\0';
}

int main(int argc, char **argv) {
	stack *s=stack_init(STACK_SIZE);
	mem *m=mem_init(MEM_SIZE);
	rm_chars_from_str(argv[1], '\n');
	if(parse(argv[1])==1) {
		return 1;
	}

	for(int pc=0, exit=0;; pc++) {
		switch(prog[pc]) {
			case OP_INC_P:
				//printf("[%d] increment pointer\n", pc);
				m->ptr++;
				break;
			case OP_DEC_P:
				//printf("[%d] decrement pointer\n", pc);
				m->ptr--;
				break;
			case OP_INC_VAL:
				//printf("[%d] increment value\n", pc);
				m->data[m->ptr]++;
				break;
			case OP_DEC_VAL:
				//printf("[%d] decrement value\n", pc);
				m->data[m->ptr]--;
				break;
			case OP_OUT:
				//printf("[%d] print\n", pc);
				putchar(m->data[m->ptr]);
				break;
			case OP_IN:
				//printf("[%d] get\n", pc);
				m->data[m->ptr]=getchar();
				break;
			case OP_JMP_FWD:
				//printf("[%d] jump forward\n", pc);
				stack_push(s, pc);
				break;
			case OP_JMP_BCK:
				//printf("[%d] jump backwards\n", pc);
				if(m->data[m->ptr]==0) {
					stack_pop(s);
				} else {
					pc=stack_peek(s);
				}
				break;
			case OP_END:
				//printf("[%d] program end\n", pc);
				exit=1;
		}
		if(exit) break;
	}
	
	printf("\n");
	stack_free(s);
	mem_free(m);
	free(prog);
}
