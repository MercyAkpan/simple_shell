#ifndef header
#define header
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
void get_pid();
void get_parentid();
int executev();
#include <sys/wait.h>
int for_proc();
int get_line();
void strtok_word();
#endif
