#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_wordtok(char *str, char *d)
{
	int iter, h, l, num, words = 0;
	char **string;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (iter = 0; str[iter] != '\0'; iter++)
		if (!is_delim(str[iter], d) && (is_delim(str[iter + 1], d) || !str[iter + 1]))
			words++;

	if (words == 0)
		return (NULL);
	string = malloc((1 + words) * sizeof(char *));
	if (string == NULL)
		return (NULL);
	for (iter = 0, h = 0; h < words; h++)
	{
		while (is_delim(str[iter], d))
			iter++;
		l = 0;
		while (is_delim(str[i + k], d) == NULL && str[iter + l])
			l++;
		string[h] = malloc((l + 1) * sizeof(char));
		if (string[h] == NULL)
		{
			for (l = 0; l < h; l++)
				free(string[l]);
			free(string);
			return (NULL);
		}
		for (num = 0; num < l; num++)
			string[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
