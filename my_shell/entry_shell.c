#include "simple_shell.h"
/**
 *
 *
 *
 *
 */
int main(void)
{
	char comm_arg[100];

	for(; ;)/*OR while(!0) or while (true)*/
	{
		prompting();
		edit_comm_arg(comm_arg, sizeof(comm_arg));
		exec_comm(comm_arg);
	}
	return (0);
}


/**
 *
 *
 */
void prompting(void);
{
	print_1out("321-->>");
}

/**
 *
 *
 */
void exec_comm(const char *comm_arg_here)
{
	pid_t child_Pid = fork();

	if (child_Pid < 0)
	{
		perror("Try to fork/duplicate process again");
		exit(EXIT_FAILURE);
	}
	else if (child_Pid == 0)
	{
		/**exec variant function here
		 * perror here
		 */
		exit (EXIT_FAILURE);
	}
	else 
	{
		/* wait process*/
	}
}

/**
 *
 *
 */
void edit_comm_arg(char *comm_arg_here, int weight)/* OR size_t*/
{
	if(!(fegts(comm_arg_here, weight, stdin)))
	{
		if(feof(stdin))
		{
			print_1out("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print_1out("Couldn't parse input correctly.\n");
			exit(EXIT_FAILURE);
		}

	}
	comm_arg_here[strcspn(comm_arg_here, "\n")] = '\0;
}
