#include "simple_shell.h"
/**
 *
 *
 *
 *
 */
void print_1out(const char *stdout)
{
	write(1, &stdout, strlen(stdout));
	/* 1 or stdout*/
}


