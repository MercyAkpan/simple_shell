#include "shell.h"

/**
 * re__all - reallocates a pointer to double the space
 * @ptrr: pointer to array
 * @space: pointer to number of elements in the old array
 * Return: pointer to the new array
 */
char **re__all(char **ptrr, size_t *space)
{
	char **clea;
	size_t iter;

	clea = malloc(sizeof(char *) * ((*space) + 10));
	if (clea == NULL)
	{
		free(ptrr);
		return (NULL);
	}
	for (iter = 0; iter < (*space); iter++)
	{
		clea[iter] = ptrr[iter];
	}
	*space += 10;
	free(ptrr);
	return (clea);
}
