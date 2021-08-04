#include <stdio.h>

#ifndef MEM_SIZE
#define MEM_SIZE 30000
#endif

int main(void) {
	char mem[MEM_SIZE]={0};
	int memloc=0, run=0;
	char *memptr=&mem[memloc];
	char in;
	
	while(1) {
		in=getchar();
		getchar();
		switch(in) {
			case '>':
				memloc++;
				run=1;
				break;
			case '<':
				memloc--;
				run=1;
				break;
			case '+':
				++*memptr;
				break;
			case '-':
				--*memptr;
				break;
			case '.':
				putchar(*memptr);
				break;
			case ',':
				*memptr=getchar();
				getchar();
				break;
			default:
				break;
		}
		
		if(run) {
			if(memloc==-1) {
				memloc=MEM_SIZE;
			} else if(memloc==MEM_SIZE+1) {
				memloc=0;
			}
			run=0;
		}
		memptr=&mem[memloc];
		
		printf("\n*memptr = int: %d, char: '%c'\nmemloc: %d\n", *memptr, *memptr, memloc);
	}
}
