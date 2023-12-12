#include "try.h"

int main ()
{
	char *space = NULL;
	long unsigned int number = 0;


	for(; ;)
	{
		write(1, "#cisfun$ \n", strlen("#cisfun$ \n"));
		getline(&space, &number, stdin);
	char *delim = " \n";
	strtok_strings(space,delim); 
	/*for(word)
	{
		printf("")
	}*/
	}
}


int strtok_strings(char *string,const char *delimitter)
{
   //     char *string = {/*"JESUS;IS;LORD;YES;:);:)\n"*/"I\nthought\nof\nseveral\nways\nto\nmake\nthis\npossible\n"};
     //   char *delimitter = ";\n";
        char *word;
        char *string2;
        int i = 0;
	//char *argv[4];
	char **argv;

	argv = malloc(sizeof(char *) * max_size);
	// *argv = malloc(sizeof(char *) * max_size);
	if(argv == NULL)
	{
		free(argv);
		perror("argv not allocated\n");
	}
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
               // printf("This is the [%d] token : %s\n",i, word);
		argv[i] = word;
		word = strtok(NULL, delimitter);
        	i++;
	}
	argv[i] = NULL;
	pid_t child_pid = fork();
	i = 0;
	if(child_pid == 0)
	{
		while (argv[i])
		{
			printf("argv[%d] output is: %s\n",i, argv[i]);
			i++;
		}
	if (execve(argv[0], argv, NULL) == -1)
		perror("NOT EXECUTED BY EXECVE\n");
	}
	else
		wait(NULL);
	return (0);
}
