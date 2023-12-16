#include "shell.h"
/**
 * check_match - CHECKS IT STRING MATCH
 * @k: CHACRTER TO ANALYSE
 * @string: STRING TO BE PARSED
 * Return: 1 if match, ELSE 0
 */
unsigned int check_match(char k, const char *string)
{
	unsigned int iter;

	for (iter = 0; string[iter] != '\0'; iter++)
	{
		if (k == string[iter])
			return (1);
	}
	return (0);
}

/**
 * new_strtok - SIMILAR TO CUSTOM STRTOK
 * @string: TO BE TOKENIZED
 * @delim: SEPARATOR
 * Return: POINTER TO NEXT TOKEN
 */
char *new_strtok(char *string, const char *delim)
{
	static char *tokenstr;
	static char *nexttok;
	unsigned int iter;

	if (string)
		nexttok = string;
	tokenstr = nexttok;
	if (!tokenstr)
		return (NULL);
	for (iter = 0; nexttok[iter] != '\0'; iter++)
	{
		if (check_match(nexttok[iter], delim) == 0)
			break;
	}
	if (nexttok[iter] == '\0' || nexttok[iter] == '#')
	{
		nexttok = NULL;
		return (NULL);
	}
	tokenstr = nexttok + iter;
	nexttok = tokenstr;
	for (iter = 0; nexttok[iter] != '\0'; iter++)
	{
		if (check_match(nexttok[iter], delim) == 1)
			break;
	}
	if (nexttok[iter] == '\0')
		nexttok = NULL;
	else
	{
		nexttok[iter] = '\0';
		nexttok = nexttok + iter + 1;
		if (*nexttok == '\0')
			nexttok = NULL;
	}
	return (tokenstr);
}
