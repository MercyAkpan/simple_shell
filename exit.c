#include "shell.h"
/**
 * exit_shell - Exits the shell with the specified status
 * @status: the exit status
 */
void exit_shell(int status, char **commands)
{
	int i;

	if (commands != NULL)
	{
		for (i = 0; commands[i] != NULL; i++)
		{
			free(commands[i]);
		}
		free(commands);
	}
	exit(status); }
