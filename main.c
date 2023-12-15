#include "shell.h"
/**
 * main - Entry point for the shell program
 * Description - This function implements a simple
 * shell that reads input commands
 * @argc: argument commands
 * @argv: list of commands
 * Return: always 0
 */
int main(int __attribute__((__unused__)) argc, char __attribute__((__unused__)) *argv[])
{
	char *lineptr = NULL, **commands;
	size_t n = 1;
	ssize_t n_read;
	int status = 127;

	lineptr = malloc(sizeof(char) * n);
	if (lineptr == NULL)
	{
		return (-1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		fflush(stdout);
		n_read = getline(&lineptr, &n, stdin);
		if (n_read == -1)
		{
			free(lineptr);
			if (isatty(STDIN_FILENO))
				printf("\n");
			exit_shell(status);
		}
		lineptr[n_read - 1] = '\0';;
		if (*lineptr == '\0')
			continue;
		commands = tokenize(lineptr, " ");
		if (commands == NULL)
		{
			perror("error");
			continue;
		}
		if (strcmp(commands[0], "exit") == 0)
				exit_shell(status);
		else if (strcmp(commands[0], "invoke_env") == 0)
				print_environment(environ);
		else
		{
			if (access(commands[0], X_OK) == -1)
				get_cmd_path(commands);
			execute_command(commands, &status);
		}
		free_commands(commands);
	}
	free(lineptr);
	return (0);
}
