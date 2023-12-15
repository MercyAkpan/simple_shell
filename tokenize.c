#include "shell.h"
/**
 * tokenize - returns a string array of strings based on a delimiter
 * @str: the string to tokenize
 * @delim: the delimiter
 * Return: a NULL-terminated string array of words
 */
char **tokenize(char *str, const char *delim)
{
	char **commands = NULL, *token, *dup_str;
	size_t num_of_tokens, i;

	/*delim = " \t\n";*/
	if (str == NULL || *str == '\0')
		return (NULL);

	dup_str = strdup(str);
	if (dup_str == NULL)
	{
		free(dup_str);
		return (NULL);
	}
	token = strtok(dup_str, delim);
	if (token == NULL)
	{
		free(dup_str);
		return (NULL);
	}
		num_of_tokens = 0;
	while (token != NULL)
	{
		++num_of_tokens;
		token = strtok(NULL, delim);
	}
	/*free(dup_str);*/
	if (num_of_tokens > 0)
	{
		commands = malloc(sizeof(char *) * (num_of_tokens + 1));
		if (commands == NULL)
		{
			free(dup_str);
			free(commands);
			exit(EXIT_FAILURE);
		}
		token = strtok(dup_str, delim);
		i = 0;
		while (token != NULL)
		{
			commands[i++] = (token);
			token = strtok(NULL, delim);
		}
		commands[i] = NULL;
	}
/*	free(dup_str);*/
/*		free(commands);*/
	return (commands);
}
