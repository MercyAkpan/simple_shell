#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
unsigned int sig_flag;

/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} varr__t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(varr__t *);
} builtins_t;

ssize_t _putss(char *string);
char *dup_str_(char *str2dup);
int _strcompare_(char *stringcomp, char *strcomp2);
char *_strcat(char *word1, char *word2);
unsigned int _strlength(char *word);
char **re__all(char **ptrr, size_t *space);
char *new_strtok(char *str, const char *delim);
void (*check_for_builtins(varr__t *sarv))(varr__t *sarv);
void neexit(varr__t *sarv);
void _env(varr__t *sarv);
void new_setenv(varr__t *sarv);
void new_unsetenv(varr__t *sarv);
void _keyy(varr__t *sarv);
char **key_find(char **environ, char *keyxx);
char *addval(char *key, char *val);
int _atoi(char *str);
void loc_check(varr__t *sarv);
int _execc_loc(char *com_nd, varr__t *sarv);
char *find__dir(char **loc);
int exec_dd(varr__t  *sarv);
int dir_checking(char *string);
void _prerr(varr__t *sarv, char *wordz);
void _out2(char *string);
char *_atoitu(unsigned int counter);


char **re__all(char **ptrr, size_t *space);
int _execc_loc(char *com_nd, varr__t *sarv);
char *find__dir(char **loc);
void loc_check(varr__t *sarv);
int exec_dd(varr__t  *vars);
int dir_checking(char *string);
ssize_t _putss(char *string);
char *dup_str_(char *str2dup);
int _strcompare_(char *stringcomp, char *strcomp2);
char *_strcat(char *word1, char *word2);
unsigned int _strlength(char *word);
void _prerr(varr__t *sarv, char *wordz);
void _out2(char *string);
char *_atoitu(unsigned int counter);
void _keyy(varr__t *sarv);
char **key_find(char **environ, char *keyxx);
char *addval(char *key, char *val);
int _atoi(char *str);
void (*check_for_builtins(varr__t *sarv))(varr__t *sarv);
void neexit(varr__t *sarv);
void _env(varr__t *sarv);
void new_setenv(varr__t *sarv);
void new_unsetenv(varr__t *sarv);
char **makenv(char **environ);
void freenv(char **env);
/*static void sig_handler(int uv);*/

int main(int argc __attribute__((unused)), char **argv, char **environment);
unsigned int check_match(char k, const char *string);
char *new_strtok(char *string, const char *delim);
char **__strtok(char *buff, char *delimitter);


#endif /* _SHELL_H_ */
