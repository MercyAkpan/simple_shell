#include "shell.h"

/**
 * _puts - writes a string to standard output
 * @str: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _putss(char *string)
{
	ssize_t numb, length;

	numb = _strlength(string);
	length = write(STDOUT_FILENO, string, numb);
	if (length != numb)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (length);
}

/**
 * _strdup - returns pointer to new mem alloc space which contains copy
 * @strtodup: string to be duplicated
 * Return: a pointer to the new duplicated string
 */
char *dup_str_(char *str2dup)
{
	char *other;

		int length, iter;

	if (str2dup == 0)
		return (NULL);

	for (length = 0; str2dup[length]; length++)
		;
	other = malloc((length + 1) * sizeof(char));

	for (iter = 0; iter <= length; iter++)
		other[iter] = str2dup[iter];

	return (other);
}

/**
 * _strcmpr - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcompare_(char *stringcomp, char *strcomp2)
{
	int iter;

	iter = 0;
	while (stringcomp[iter] == strcomp2[iter])
	{
		if (stringcomp[iter] == '\0')
			return (0);
		iter++;
	}
	return (stringcomp[iter] - strcomp2[iter]);
}

/**
 * _strcat - concatenates two strings
 * @strc1: first string
 * @strc2: second string
 * Return: pointer
 */
char *_strcat(char *word1, char *word2)
{
	char *word3;
	unsigned int length1, length2, totlen, iter, j;

	length1 = 0;
	length2 = 0;
	if (word1 == NULL)
		length1 = 0;
	else
	{
		for (length1 = 0; word1[length1]; length1++)
			;
	}
	if (word2 == NULL)
		length2 = 0;
	else
	{
		for (length2 = 0; word2[length2]; length2++)
			;
	}
	totlen = length1 + length2 + 2;
	word3 = malloc(totlen * sizeof(char));
	if (word3 == NULL)
		return (NULL);
	for (iter = 0; iter < length1; iter++)
		word3[iter] = word1[iter];
	word3[iter] = '/';
	for (j = 0; j < length2; j++)
		word3[iter + j + 1] = word2[j];
	word3[length2 + length1 + 1] = '\0';
	return (word3);
}
/**
 * _strlen - returns the length of a string
 * @str: string to be measured
 * Return: length of string
 */
unsigned int _strlength(char *word)
{
	unsigned int length;

	length = 0;

	for (length = 0; word[length]; length++)
		;
	return (length);
}
