#include "header.h"
/**
  *
  *
  *
  *
  */
int main ()
{
//	get_pid();
//	get_parentid();
//	for_proc();
//	executev();
//	get_line();
	strtok_word();
}


void get_pid()
{
	pid_t pid = getpid();

	printf("This is the current process id : %d\n", pid);

}

void get_parentid()
{
	pid_t ppid = getppid();

	printf("PARENT PROCESS ID REMAINS: %d\n", ppid);
}

int for_proc()
{
	int child_proc;


	child_proc = fork();
		if (child_proc == -1)
			perror("ERROR\n");
		if (child_proc == 0)
		{
			printf("A child here\n");
		}
		else
		{
			wait(NULL);
			printf("THE PARENT HERE\n");
		}
		return(0);
}

int executev()
{
	char *argv[] = {"/usr/bin/ls", "-1", ".", NULL};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("NOPE NOT EXECUTED\n");
	}
}

int get_line()
{
	long unsigned int numb = 0;
	char *space = NULL;
	int count = getline(&space, &numb, stdin);
	
	if(count == -1)
		perror("NOT GIVEN SPACE\n");
	printf("Amount of allocated space is : %d\n", count);
}



void strtok_word()
{
	char string[] = {"WHO IS IT ??"};
	char *separate = " \n";
	char *word;

	word = strtok(string, separate);
	while(word)
	{
		printf("%s\n",word);
		word = strtok(NULL, separate);
	}
}
