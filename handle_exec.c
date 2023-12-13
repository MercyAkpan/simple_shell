#include "shell.h"
/**
 * execute_command - function to execute command variables
 * @commands: commands to be executed
 * @status: status parameter
 * Return: finastatus
 */
int execute_command(char **commands, int *status)
{
	int wstatus, finalStatus;

	pid_t child = fork(), w;

	if (child == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child == 0)
	{
		if (execve(commands[0], commands, environ) == -1)
		{
			perror("execve");
			handle_exec_error(commands, status);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		do {
			w = waitpid(child, &wstatus, WUNTRACED | WCONTINUED);
			if (w == -1)
				perror("waitpid");
			if (WIFEXITED(wstatus))
				finalStatus = WEXITSTATUS(wstatus);
			else if (WIFSIGNALED(wstatus))
				finalStatus = -1 * WTERMSIG(wstatus);
			else if (WIFSTOPPED(wstatus))
				finalStatus = -1 * WSTOPSIG(wstatus);
			else if (WIFCONTINUED(wstatus))
				finalStatus = -1;
		} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
	}
	return (finalStatus);
}
/**
 * handle_exec_error - function to hand errors
 * @commands: variable commands
 * @status: status parameter
 */
void handle_exec_error(char **commands, int *status)
{
	perror("execve");
	fprintf(stderr, "Failed to execute command: %s\n", commands[0]);
	*status = 127;
}
