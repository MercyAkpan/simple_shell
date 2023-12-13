#include "shell.h"
/**
 * main - Entry point for the shell program
 * Description - This function implements a simple
 * shell that reads input commands
 * @argc: argument commands
 * @argv: list of commands
 * Return: always 0
 */
int main(__attribute__((unused))int argc, __attribute__((unused))char *argv[])
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t n_read;
	int status = 0;
	char **commands;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("MercyComfort$ ");
		fflush(stdout);
		n_read = getline(&lineptr, &n, stdin);
		if (n_read == -1)
		{
			free(lineptr);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit_shell(status, commands);
		}
		lineptr[n_read - 1] = '\0';
		if (*lineptr == '\0')
			continue;

		commands = tokenize(lineptr, " ");
		if (commands != NULL)
		{
			if (strcmp(commands[0], "exit") == 0)
				exit_shell(status, commands);
			else
			{
				if (access(commands[0], X_OK) == -1)
				{
					get_cmd_path(commands);
				        execute_command(commands, &status);
					continue;
				}
			}
		}
		free_commands(commands);
	}
	return (0);
}
