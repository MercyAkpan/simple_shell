#include "shell.h"
#define BUFFER_SIZE 32
#define MAX_NUM 1024
/**
 * get_cmd_path - function to the enviroment path
 * @command: commands to be passed
 */
void get_cmd_path(char **command)
{
	char *dir = NULL, *path = NULL, *path_dir, *dup_str;
	int check;

	if (*command == NULL || command == NULL)
		return;

	path_dir = getenv("PATH");
	if (path_dir == NULL)
		return;

	dup_str = strdup(path_dir);
	dir = strtok(dup_str, ":");

	while (dir != NULL)
	{
		path = malloc(sizeof(char) * (strlen(*command) + strlen(dir) + 1 + BUFFER_SIZE));
		if (path == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			free(path);
			free(dup_str);
			return;
		}
	check = snprintf(path, MAX_NUM, "%s/%s", dir, *command);
	if (check < 0)
	{
		write(1, "error",strlen("error"));
		free(path);
		free(dup_str);
		return;
	}
	else if (check >= MAX_NUM)
		write(1, "some path may be truncated", strlen("some path may be truncated"));
	else
	{
		if (access(path, X_OK) == 0)
		{
			/*free(*command);*/
			*command = strdup(path);
			free(path);
			break;
		}
		free(path);
		dir = strtok(NULL, ":");
	}
	}
	free(dup_str);
	free(*command);
}
