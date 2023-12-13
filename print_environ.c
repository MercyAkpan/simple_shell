#include "shell.h"
/**
 * print_envronment - function prints the environment
 * @environ: array pointer to environment variables
 */
void print_environment(char **environ)
{
        char **env = environ;
	
	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
