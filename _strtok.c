#include"shell.h"
/**
 * _strtok - split a string of characters
 * @str: The input string to be splitted
 * @delim: delimiter
 * Return: An array of characters, terminated by a NULL pointer
 */
char* _strtok(const char* str, const char* delim)
{
	static const char* saved_str = NULL;
	const char* start;
	char* token;
	size_t token_len;

	if (str != NULL)
	{
		saved_str = str;
	}
	while (*saved_str && strchr(delim, *saved_str) != NULL)
	{
		saved_str++;
	}
	if (*saved_str == '\0')
	{
		return (NULL);
	}
	start = saved_str;
	while (*saved_str && strchr(delim, *saved_str) == NULL)
	{
		saved_str++;
	}
	token_len = saved_str - start;

	token = (char*)malloc(token_len + 1);
	if (token == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	strncpy(token, start, token_len);
	token[token_len] = '\0';
	return (token);
}
