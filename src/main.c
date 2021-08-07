#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "common.h"
#include "run.h"


struct option long_options[] = {
		{"compile", required_argument, NULL, 'c'},
		{"program", required_argument, NULL, 'p'},
		{"help", no_argument, NULL, 'h'},
		{"version", no_argument, NULL, 'v'},
		{0, 0, NULL, 0}
};

int main(int argc, char **argv) {
	if(!argv[1]) {
		fprintf(stderr, "ERROR: insufficient arguments provided!\nUse \"--help\" argument for help.\n");
		return 1;
	}
	
	int status=0, opt;
	opt=getopt_long(argc, argv, "c:p:hv", long_options, NULL);
	if(opt!=-1) {
		switch(opt) {
			case 'h':
				printf("\e[1mUSAGE:\e[0m\n%s [option]\n", argv[0]);
				printf("\e[1mOPTIONS:\e[0m\n-p|--program '[brainfuck code]' - run brainfuck code directly.\n-c|--compile [in.b] - compile brainfuck code into C code. the output file will be called 'brainf.out.c'.\n-h|--help - print this help.\n-v|--version - print version.\n");
				break;
			case 'v':
				printf("\e[1mbrainf\e[0m version %s built on %s.\n", VER, __TIMESTAMP__);
				break;
			case 'p':
				status=run(optarg);
				break;
			case 'c':
				status=compile_from_file(optarg, "brainf.out.c");
				break;
			default:
				break;
		}
	} else {
		status=run_from_file(argv[1]);
	}
	return status;
}
