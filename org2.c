#include "shell.h"

/**
 * _kkey - make environment variable
 * @sarv: pointer to struct of variables
 * Return: void
 */
void _keyy(varr__t *sarv)
{
	unsigned int iter;
	char **nenv;

	for (iter = 0; sarv->env[iter] != NULL; iter++)
		;
	nenv = malloc(sizeof(char *) * (1 + 1 + iter));
	if (!nenv)
	{
		_prerr(sarv, NULL);
		sarv->status = 127;
		neexit(sarv);
	}
	for (iter = 0; sarv->env[iter] != NULL; iter++)
		nenv[iter] = sarv->env[iter];
	nenv[iter] = addval(sarv->av[1], sarv->av[2]);
	if (!(nenv[iter]))
	{
		_prerr(sarv, NULL);
		free(sarv->buffer);
		free(sarv->commands);
		free(sarv->av);
		freenv(sarv->env);
		free(nenv);
		exit(127);
	}
	nenv[1 + iter] = NULL;
	free(sarv->env);
	sarv->env = nenv;
}

/**
 * key_find - finds an environment variable
 * @environ: array of environment variables
 * @keyxx: environment variable to be find
 * Return: pointer to address of the environment variable
 */
char **key_find(char **environ, char *keyxx)
{
	unsigned int iter, iter2, length;

	length = _strlength(keyxx);
	for (iter = 0; environ[iter] != NULL; iter++)
	{
		for (iter2 = 0; iter2 < length; iter2++)
			if (keyxx[iter2] != environ[iter][iter2])
				break;
		if (iter2 == length && environ[iter][iter2] == '=')
			return (&environ[iter]);
	}
	return (NULL);
}

/**
 * addval - create a new environment variable string
 * @key: variable name
 * @val: variable value
 * Return: pointer to the new string;
 */
char *addval(char *key, char *val)
{
	unsigned int len0, len2, iter = 0, k = 0;
	char *nwr;

	len0 = _strlength(key);
	len2 = _strlength(val);
	nwr = malloc(sizeof(char) * (len0 + 2 + len2));
	if (!nwr)
		return (NULL);
	for (iter = 0; key[iter] != '\0'; iter++)
		nwr[iter] = key[iter];
	nwr[iter] = '=';
	for (k = 0; val[k] != '\0'; k++)
		nwr[iter + k + 1] = val[k];
	nwr[iter + k + 1] = '\0';
	return (nwr);
}

/**
 * _atoi - converts a string into an integer
 * @str: string to convert
 * Return: integer value -1
 */
int _atoi(char *str)
{
	unsigned int iter = 0, j = 0;
	int num = 0, numt;

	numt = INT_MAX;
	for (j = 0; numt != 0; j++)
		numt /= 10;
	for (iter = 0; str[iter] != '\0' && iter < j; iter++)
	{
		num = num * 10;
		if (str[iter] < '0' || str[iter] > '9')
			return (-1);
		if ((iter == j - 1) && (str[iter] - '0' > INT_MAX % 10))
			return (-1);
		num += str[iter] - '0';
		if ((iter == j - 2) && (str[iter + 1] != '\0') && (num > INT_MAX / 10))
			return (-1);
	}
	if (iter > j)
		return (-1);
	return (num);
}
