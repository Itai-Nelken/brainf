#include "common.h"

mem *mem_init(size_t size);

void mem_free(mem *m);

int run(char *str);

int run_from_file(char *filename);

int compile_from_file(char *filename, char *outname);