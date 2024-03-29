#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "stack.h"
#include "common.h"

mem *mem_init(size_t size) {
	mem *m=malloc(sizeof(mem));
	m->data=calloc(size*sizeof(char *), sizeof(char));
	m->ptr=0;
	return m;
}

void mem_free(mem *m) {
	free(m->data);
	free(m);
}

int *parse(char *str) {
	int pc=0;
	int *prog=malloc(strlen(str)*sizeof(int *)+1);
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
				pc--;
				//fprintf(stderr, "ERROR: invalid instruction \"%c\" (character %d)!\n", str[pc], pc+1);
				//return NULL;
				break;
		}
		pc++;
	}
	prog[pc]=OP_END;
	return prog;
}

void execute(int *prog) {
	stack *s=stack_init(STACK_SIZE);
	mem *m=mem_init(MEM_SIZE);
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
				break;
		}
		if(exit) break;
	}
	printf("\n");
	mem_free(m);
	stack_free(s);
}

int b2c(int *prog, char *filename) {
	FILE *out=fopen(filename, "w");
	if(out==NULL) {
		perror("fopen()");
		return 1;
	}
	fprintf(out, "#include <stdio.h>\nint main(void) {\n");
    fprintf(out, "char mem[30000]={0};\nchar *ptr=mem;\n");
	for(int pc=0, exit=0;; pc++) {
		switch(prog[pc]) {
	   		case OP_INC_P:
				fprintf(out, "++ptr;\n");
	   			break;
	   		case OP_DEC_P:
            	fprintf(out, "--ptr;\n");
	   			break;
	   		case OP_INC_VAL:
            	fprintf(out, "++*ptr;\n");
	   			break;
	   		case OP_DEC_VAL:
            	fprintf(out, "--*ptr;\n");
	   			break;
	   		case OP_OUT:
            	fprintf(out, "putchar(*ptr);\n");
	   			break;
	   		case OP_IN:
            	fprintf(out, "*ptr=getchar();\n");
	   			break;
	   		case OP_JMP_FWD:
            	fprintf(out, "while(*ptr) {\n");
	   			break;
	   		case OP_JMP_BCK:
               fprintf(out, "}\n");
               break;
            case OP_END:
            	exit=1;
            	break;
	   }
	   if(exit) break;
	}
	fprintf(out, "return 0;\n}\n");
	fclose(out);
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

int run(char *str) {
	int *prog;
	rm_chars_from_str(str, '\n');
	if((prog=parse(str))==NULL) {
		return 1;
	}
	execute(prog);
	free(prog);
	return 0;
}

int run_from_file(char *filename) {
	int c, size=100, i=0;
	char *str;
	FILE *file=fopen(filename, "r");
	if(file==NULL) {
		fprintf(stderr, "fopen(): failed to open file \"%s\": %s!\n", filename, strerror(errno));
		return 1;
	}
	str=malloc(size);

	while((c=fgetc(file))!=EOF) {
		if(i==size) {
			size=size+100;
			str=realloc(str, size);
		}
		str[i++]=(char)c;
	}
	str[i]='\0';
	fclose(file);
	int ret = run(str);
	free(str);
	return ret;
}

int compile_from_file(char *filename, char *outname) {
	int c, size=100, i=0, *prog;
	char *str;
	FILE *file=fopen(filename, "r");
	if(file==NULL) {
		fprintf(stderr, "fopen(): failed to open file \"%s\": %s!\n", filename, strerror(errno));
		return 1;
	}
	str=malloc(size);

	while((c=fgetc(file))!=EOF) {
		if(i==size) {
			size=size+100;
			str=realloc(str, size);
		}
		str[i++]=(char)c;
	}
	str[i]='\0';
	fclose(file);
	rm_chars_from_str(str, '\n');
	if((prog=parse(str))==NULL) {
		return 1;
	}
	i=b2c(prog, outname);
	free(prog);
	free(str);
	return i;
}
