#include "shell.h"

/**
 * make_env - make the shell environment from the environment passed to main
 * @env: environment passed to main
 *
 * Return: pointer to the new environment
 */
char **makenv(char **environ)
{
	char **nenv = NULL;
	size_t iter = 0;

	for (iter = 0; environ[iter] != NULL; iter++)
		;
	nenv = malloc(sizeof(char *) * (iter + 1));
	if (!nenv)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (iter = 0; environ[iter] != NULL; iter++)
		nenv[iter] = dup_str_(environ[iter]);
	nenv[iter] = NULL;
	return (nenv);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void freenv(char **env)
{
	unsigned int iter = 0;

	for (iter = 0; env[iter] != NULL; iter++)
		free(env[iter]);
	free(env);
}
