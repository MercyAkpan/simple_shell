#include "try.h"
void main(void)
{
	get_pid();
//	fork_process();
//	return (0);
//	execve_process();
//	get_line_buffer();
//	strtok_strings();
//	fork_5();
}


/*int main(unsigned int argc, char *argv[]) 
{
	
	unsigned int i = 0;
	printf("argc OR total count of command line arguments is : [%u]\n",argc);

	while(i < argc)
	{
		printf("This is the argc [%u] argc'th value : %s\n",i, argv[i]);
	++i;
	}
	return (0);
}
*/
void get_pid(void)
{
	pid_t /*current_pid,*/ current_ppid;

	current_ppid = getppid();
//	current_pid = getpid();
/*	write(1, &current_pid, strlen((const char *__s)(current_pid)));*/
//	printf("The current pid is: %u\n", current_pid);
	printf("PARENT PID IS: %u\n", current_ppid);
}

int fork_process(void)
{
	pid_t pid;
	/*fork_on =*/pid = fork();

	if (pid == -1)
	{
		printf("UNSUCCESSFUL FORKING ,try again\n\n");
	/*	return (1);*/
	}
	else if (pid == 0)
	{
		/*sleep(9);*/
		printf("CHILD IS AROUND\n");
	//return (0);
	}
	else 
	{
		wait(NULL);
		//sleep(30);
		printf("PARENT EXECUTED FIRST\n");
	}
	return (0);
}

int execve_process()
{
	char  *argv[] = {"/usr/bin/ls", "-1", "../", NULL};
	pid_t pid = fork();
	//int val = execve(argv[0], argv, NULL);

	if (pid == 0)
		{
			int val = execve(argv[0], argv, NULL);
			
			printf("This doesn't get executed\n");
			if (val == -1)
			{
				perror("This was not executed\n");
			}
			return (0);
		}
	else
	{
		wait(NULL);
		printf("This still got exectuted :) :) \n");
	}
	return (0);
}
int get_line_buffer()
{
	size_t num = 3;
	char *linepointer = malloc(sizeof(char) * num);

	
	if (linepointer == NULL)
	{
		free (linepointer);
		return (1);
	}
	printf("Enter your name,please:\n");	
	int val = getline(&linepointer, &num, stdin);

		if (val == -1)
		{
			free(linepointer);
			//free (val); - HOW WOULD I NOW FREE GETLINE IF IT FAILED, AS STATED IN THE MAN PAGES?? - I'm not sure if i need to even free getline.
			return (1);
		}
		// To remove - printf("Enter your name,please:\n ");
		printf("NOTE BEFORE: I removed the newline xter \\n\n");
		printf("SUCCESSFULL :) :) :)\nThis buffer contains : %u characters\n", (val - 1));
	return (0);
}

/*int strtok_strings(void)
{
	char *string = {"JESUS;IS;LORD;YES;:);:)\n"};
	char delimitter = ';';
	char *word;
	char *string2;
	int i = 0;

	string2 = malloc(sizeof(char) * strlen(string));
	if (string2 == NULL)
	{
		free(string2);
		return (1);
	}
	string2 = strdup(string);
	//strncpy(string,
	word = strtok(string2, &delimitter);
	i++;
	printf("This is the [%d] token : %s\n",i, word);
	word = strtok(NULL, &delimitter);

	while (word)
	{
		++i;
		printf("This is the [%d] token : %s\n",i, word);
		word = strtok(NULL, &delimitter);
	}
	return (0);
}*/


int strtok_strings(void)
{
        char *string = {/*"JESUS;IS;LORD;YES;:);:)\n"*/"I\nthought\nof\nseveral\nways\nto\nmake\nthis\npossible\n"};
	char *delimitter = ";\n";
        char *word;
        char *string2;
        int i = 0;

        string2 = malloc(sizeof(char) * strlen(string));
        if (string2 == NULL)
        {
                free(string2);
                return (1);
        }
        string2 = strdup(string);
        //strncpy(string,
        word = strtok(string2, delimitter);

        while (word)
        {
                ++i;
                printf("This is the [%d] token : %s\n",i, word);
                word = strtok(NULL, delimitter);
        }
        return (0);
}

int fork_5()
{	
	char *argue[] = {"/usr/bin/ls", "-l", "/tmp", NULL};
	int i, child_pid;

	for (i = 1; i <= 5; ++i)
	{
		child_pid = fork();
	if (child_pid == -1)
	{
		perror("ERROR ON THIS CHILD\n");
	}

	if (child_pid == 0)
	{
		if(execve(argue[0], argue, NULL) == -1)
		{
			perror("\"THIS WOULD PRINT OUT AS AN ERROR");
		}
	}
	else
	wait(NULL);
	}
	return (0);
}
