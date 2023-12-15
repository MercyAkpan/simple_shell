#include "shell.h"
/**
 * path_execute - executes a command in the path
 * @command: full path to the command
 * @vars: pointer to struct of variables
 * Return: 0 on succcess, 1 on failure
 */
int _execc_loc(char *com_nd, varr__t *sarv)
{
	pid_t childprocess;

	if (access(com_nd, X_OK) == 0)
	{
		childprocess = fork();
		if (childprocess == -1)
		_prerr(sarv, NULL);
		if (childprocess == 0)
		{
			if (execve(com_nd, sarv->av, sarv->env) == -1)
				_prerr(sarv, NULL);
		}
		else
		{
			wait(&sarv->status);
			if (WIFEXITED(sarv->status))
				sarv->status = WEXITSTATUS(sarv->status);
			else if (WIFSIGNALED(sarv->status) && WTERMSIG(sarv->status) == SIGINT)
				sarv->status = 130;
			return (0);
		}
		sarv->status = 127;
		return (1);
	}
	else
	{
		_prerr(sarv, ": Permission denied\n");
		sarv->status = 126;
	}
	return (0);
}

/**
 * find_path - finds the PATH variable
 * @env: array of environment variables
 *
 * Return: pointer to the node that contains the PATH, or NULL on failure
 */
char *find__dir(char **loc)
{
	char *path_loc = "PATH=";
	unsigned int iter, iter2;

	for (iter = 0; loc[iter] != NULL; iter++)
	{
		for (iter2 = 0; iter2 < 5; iter2++)
			if (path_loc[iter2] != loc[iter][iter2])
				break;
		if (iter2 == 5)
			break;
	}
	return (loc[iter]);
}
/**
 * check_for_path - checks if the command is in the PATH
 * @vars: variables
 *
 * Return: void
 */
void loc_check(varr__t *sarv)
{
	char *path, *path_dupl = NULL, *check = NULL, **path_toks;
	unsigned int iter = 0, run = 0;
	struct stat buff;

	if (dir_checking(sarv->av[0]))
		run = exec_dd(sarv);
	else
	{
		path = find__dir(sarv->env);
		if (path)
		{
			path_dupl = dup_str_(path + 5);
			path_toks = __strtok(path_dupl, ":");
			for (iter = 0; path_toks && path_toks[iter]; iter++, free(check))
			{
				check = _strcat(path_toks[iter], sarv->av[0]);
				if (stat(check, &buff) == 0)
				{
					run = _execc_loc(check, sarv);
					free(check);
					break;
				}
			}
			free(path_dupl);
			if (!path_toks)
			{
				sarv->status = 127;
				neexit(sarv);
			}
		}
		if (path_toks[iter] == NULL || path == NULL)
		{
			_prerr(sarv, ": not found\n");
			sarv->status = 127;
		}
		free(path_toks);
	}
	if (run == 1)
		neexit(sarv);
}

/**
 * execute_cwd - executes the command in the current working directory
 * @vars: pointer to struct of variables
 *
 * Return: 0 on success, 1 on failure
 */
int exec_dd(varr__t  *sarv)
{
	pid_t childpid;
	struct stat buff;

	if (stat(sarv->av[0], &buff) == 0)
	{
		if (access(sarv->av[0], X_OK) == 0)
		{
			childpid = fork();
			if (childpid == -1)
				_prerr(sarv, NULL);
			if (childpid == 0)
			{
				if (execve(sarv->av[0], sarv->av, sarv->env) == -1)
					_prerr(sarv, NULL);
			}
			else
			{
				wait(&sarv->status);
				if (WIFEXITED(sarv->status))
					sarv->status = WEXITSTATUS(sarv->status);
				else if (WIFSIGNALED(sarv->status) && WTERMSIG(sarv->status) == SIGINT)
					sarv->status = 130;
				return (0);
			}
			sarv->status = 127;
			return (1);
		}
		else
		{
			_prerr(sarv, ": Permission denied\n");
			sarv->status = 126;
		}
			return (0);
	}
	_prerr(sarv, ": not found\n");
	sarv->status = 127;
	return (0);
}

/**
 * check_for_dir - checks if the command is a part of a path
 * @str: command
 *
 * Return: 1 on success, 0 on failure
 */
int dir_checking(char *string)
{
	unsigned int iter;

	for (iter = 0; string[iter]; iter++)
	{
		if (string[iter] == '/')
			return (1);
	}
	return (0);
}
