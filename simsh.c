#include "shell.h"
unsigned int sig_flag;
/* global variable for ^C handling
 * sig_handler - handles ^C signal interupt
 * @uv: unused variable
 * Return: void
 */
static void sig_handler(int uv)
{
	(void) uv;
	if (sig_flag == 0)
		_putss("\n$ ");
	else
		_putss("\n");
}

/**
 * main - main function
 * @argc: number of arguments passed
 * @argv: array of arguments passed
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t bufferlen = 0;
	unsigned int ispipe = 0, iter;
	varr__t sarv = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	sarv.argv = argv;
	sarv.env = makenv(environment);
	signal(SIGINT, sig_handler);
	if (!isatty(STDIN_FILENO))
		ispipe = 1;
	if (ispipe == 0)
		_putss("$ ");
	sig_flag = 0;
	while (getline(&(sarv.buffer), &bufferlen, stdin) != -1)
	{
		sig_flag = 1;
		sarv.count++;
		sarv.commands = __strtok(sarv.buffer, ";");
		for (iter = 0; sarv.commands && sarv.commands[iter] != NULL; iter++)
		{
			sarv.av = __strtok(sarv.commands[iter], "\n \t\r");
			if (sarv.av && sarv.av[0])
				if (!check_for_builtins(&sarv))
					loc_check(&sarv);
		free(sarv.av);
		}
		free(sarv.buffer);
		free(sarv.commands);
		sig_flag = 0;
		if (ispipe == 0)
			_putss("$ ");
		sarv.buffer = NULL;
	}
	if (ispipe == 0)
		_putss("\n");
	freenv(sarv.env);
	free(sarv.buffer);
	exit(sarv.status);
}
