#include "shell.h"
/**
  * execute_env_command - this is the command
  *@environ: This path.
  */
void execute_env_command(char **environ)
{
	char *command[] = {"sh", "-c", "env", NULL};
	pid_t childpid = fork();

	if (childpid == 0)
	{
		execve("/bin/sh", command, environ);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (childpid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(childpid, NULL, 0);
	}

}
