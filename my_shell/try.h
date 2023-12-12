#ifndef try_h
#define try_h
#include <stdio.h>
#include <string.h>
#include <unistd.h>
int fork_process(void);
#include <sys/wait.h>
int execve_process();
int get_line_buffer();
#include <stdlib.h>
#include <sys/wait.h>
void get_pid(void);
//int strtok_strings(void);
int strtok_strings(char *space, const char *delim);
int fork_5();
#ifndef max_sixe
#define max_size 6678
#endif /* max_size*/
#endif /*try_h ends*/
