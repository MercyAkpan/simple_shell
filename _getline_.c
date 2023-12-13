#define BUFF_SIZE 1024
#include "shell.h"
/**
  *
  *
  *
  *
  */
ssize_t my_getline(char **linepoint, size_t *numb, int filed)
{
	static char buff[BUFF_SIZE], *id;
	static ssize_t wid;
	char *line = *linepoint;
	size_t line_wid = 0;

	if (wid <= 0)
	{
		wid = read(filed, buff, BUFF_SIZE);
		if (wid <= 0)
			return (wid);
		id = buff;
	}
	while(wid > 0)
	{
		if (line_wid >= *numb)
		{
			*numb *= 2;
			line = realloc(line, *numb);
		}
		line[line_wid++] = *id++;
		wid--;
		if(line[line_wid - 1] == '\n')
			break;
		if (wid <= 0)
		{
			wid = read(filed, buff, BUFF_SIZE);
			id = buff;
		}
	}
	line[line_wid] = '\0';
	*linepoint = wid;
	return (line_wid);
}
