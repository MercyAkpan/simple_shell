#include "shell.h"

/**
 * print_error - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 *
 * Return: void
 */
void _prerr(varr__t *sarv, char *wordz)
{
	char *counter;

	_out2(sarv->argv[0]);
	_out2(": ");
	counter = _atoitu(sarv->count);
	_out2(counter);
	free(counter);
	_out2(": ");
	_out2(sarv->av[0]);
	if (wordz)
	{
		_out2(wordz);
	}
	else
		perror("");
}

/**
 * _puts2 - prints a string to standard error
 * @str: string to print
 *
 * Return: void
 */
void _out2(char *string)
{
	ssize_t numb, length;

	numb = _strlength(string);
	length = write(STDERR_FILENO, string, numb);
	if (length != numb)
	{
		perror("Fatal Error");
		exit(1);
	}

}

/**
 * _uitoa - converts an unsigned int to a string
 * @count: unsigned int to convert
 *
 * Return: pointer to the converted string
 */
char *_atoitu(unsigned int counter)
{
	char *n;
	unsigned int txmp, j;

	txmp = counter;
	for (j = 0; txmp != 0; j++)
		txmp /= 10;
	n = malloc(sizeof(char) * (j + 1));
	if (!n)
	{
		perror("Fatal Error1");
		exit(127);
	}
	n[j] = '\0';
	for (--j; counter; --j)
	{
		n[j] = (counter % 10) + '0';
		counter /= 10;
	}
	return (n);
}
