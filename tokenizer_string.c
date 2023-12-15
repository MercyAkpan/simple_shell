#include "shell.h"

/**
 * tokenize - tokenizes a buffer with a delimiter
 * @buffer: buffer to tokenize
 * @delimiter: delimiter to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **__strtok(char *buff, char *delimitter)
{
	char **tok = NULL;
	size_t iter = 0, counter = 10;

	if (buff == NULL)
		return (NULL);
	tok = malloc(sizeof(char *) * counter);
	if (tok == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tok[iter] = new_strtok(buff, delimitter)) != NULL)
	{
		iter++;
		if (iter == counter)
		{
			tok = re__all(tok, &counter);
			if (!tok)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}
	return (tok);
}
