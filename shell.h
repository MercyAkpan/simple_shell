#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stddef.h>

#define CHUNK_SIZE 1024

extern char **environ;
extern int status;

void free_commands(char **commands);
char* _strtok(const char* str, const char* delim);
char **tokenize(char *str, const char *delim);
void get_cmd_path(char **pathname);
void exit_shell(int status, char **commands);
int main(int argc, char *argv[]);
int execute_command(char **commands, int *status);
void handle_exec_error(char **commands, int *status);
int countcharacters(const char *str);
char *copycharacters(const char *str, int start, int end);

#endif
