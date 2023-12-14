#include "shell.h"
/**
 * get_cmd_path - function to the enviroment path
 * @command: commands to be passed
 */
void get_cmd_path(char **command)
{
	char *dir = NULL, *path = NULL, *path_dir, *dup_str;

	if (*command == NULL || command == NULL)
		return;

	path_dir = getenv("PATH");
	if (path_dir == NULL)
		return;

	dup_str = strdup(path_dir);
	dir = strtok(dup_str, ":");

	while (dir != NULL)
	{
		path = malloc(sizeof(char) * (strlen(*command) + strlen(dir) + 1));
		if (path == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			free(dup_str);
			return;
		}
		sprintf(path, "%s/%s", dir, *command);
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
	free(dup_str);
	free(*command);
}
