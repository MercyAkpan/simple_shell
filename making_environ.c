#include "shell.h"
/***
  * execute_env_command -
  *@environ:
  */
void execute_env_command(char **environ)
{
	char *command[] = {"sh", "-c", "env", NULL};

	pid_t childpid = fork();
	if(childpid == 0)
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


/*int main(int argc, char **argv, char **environ)
{
	if (argc > 1 && strcmp(argv[1],"invoke_env") == 0)
		print_environment (environ);
	else
		execute_env_command(environ);
	return (0);
}*/
