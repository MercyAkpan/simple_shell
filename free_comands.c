#include "shell.h"
/**
 * free_commands - Frees the memory allocated for an array of commands.
 * @commands: Array of commands to be freed
 */
void free_commands(char **commands)
{
	for (size_t i = 0; commands[i] != NULL; i++)
	{
		free(commands[i]);
		commands[i] = NULL;
	}
	free(commands);
}
