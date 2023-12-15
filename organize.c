#include "shell.h"

/**
 * check_for_builtins - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*check_for_builtins(varr__t *sarv))(varr__t *sarv)
{
	unsigned int iter;
	builtins_t check[] = {
		{"exit", neexit},
		{"env", _env},
		{"setenv", new_setenv},
		{"unsetenv", new_unsetenv},
		{NULL, NULL}
	};

	for (iter = 0; check[iter].f != NULL; iter++)
	{
		if (_strcompare_(sarv->av[0], check[iter].name) == 0)
			break;
	}
	if (check[iter].f != NULL)
		check[iter].f(sarv);
	return (check[iter].f);
}

/**
 * new_exit - exit program
 * @vars: variables
 * Return: void
 */
void neexit(varr__t *sarv)
{
	int status;

	if (_strcompare_(sarv->av[0], "exit") == 0 && sarv->av[1] != NULL)
	{
		status = _atoi(sarv->av[1]);
		if (status == -1)
		{
			sarv->status = 2;
			_prerr(sarv, ": Illegal number: ");
			_out2(sarv->av[1]);
			_out2("\n");
			free(sarv->commands);
			sarv->commands = NULL;
			return;
		}
		sarv->status = status;
	}
	free(sarv->buffer);
	free(sarv->av);
	free(sarv->commands);
	freenv(sarv->env);
	exit(sarv->status);
}

/**
 * _env - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void _env(varr__t *sarv)
{
	unsigned int iter;

	for (iter = 0; sarv->env[iter]; iter++)
	{
		_putss(sarv->env[iter]);
		_putss("\n");
	}
	sarv->status = 0;
}

/**
 * new_setenv - create a new environment variable, or edit an existing variable
 * @vars: pointer to struct of variables
 *
 * Return: void
 */
void new_setenv(varr__t *sarv)
{
	char **keyy;
	char *varr;

	if (sarv->av[1] == NULL || sarv->av[2] == NULL)
	{
		_prerr(sarv, ": Incorrect number of arguments\n");
		sarv->status = 2;
		return;
	}
	keyy = key_find(sarv->env, sarv->av[1]);
	if (!keyy) 
		_keyy(sarv);
	else
	{
		varr = addval(sarv->av[1], sarv->av[2]);
		if (varr == NULL)
		{
			_prerr(sarv, NULL);
			free(sarv->buffer);
			free(sarv->commands);
			free(sarv->av);
			freenv(sarv->env);
			exit(127);
		}
		free(*keyy);
		*keyy = varr;
	}
	sarv->status = 0;
}

/**
 * new_unsetenv - remove an environment variable
 * @vars: pointer to a struct of variables
 *
 * Return: void
 */
void new_unsetenv(varr__t *sarv)
{
	char **key, **newenv;

	unsigned int iter, k;

	if (sarv->av[1] == NULL)
	{
		_prerr(sarv, ": Incorrect number of arguments\n");
		sarv->status = 2;
		return;
	}
	key = key_find(sarv->env, sarv->av[1]);
	if (!key)
	{
		_prerr(sarv, ": No variable to unset");
		return;
	}
	for (iter = 0; sarv->env[iter] != NULL; iter++)
		;
	newenv = malloc(sizeof(char *) * iter);
	if (!newenv)
	{
		_prerr(sarv, NULL);
		sarv->status = 127;
		neexit(sarv);
	}
	for (iter = 0; sarv->env[iter] != *key; iter++)
		newenv[iter] = sarv->env[iter];
	for (k = iter + 1; sarv->env[k] != NULL; k++, iter++)
		newenv[iter] = sarv->env[k];
	newenv[iter] = NULL;
	free(*key);
	free(sarv->env);
	sarv->env = newenv;
	sarv->status = 0;
}
