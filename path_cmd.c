#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "header.h"
#define BUFFER 512

extern char **environ;
/* this function is like "which" command for the $PATH env variable */
int path_cmd(char **tokens)
{
	char *path, *value, *p_cpy;
	struct dirent *dirc;
	DIR *dir;
	int i;

	p_cpy = malloc(sizeof(char) * BUFFER);
	if (!p_cpy)
	{
		printf("Error: p_cpy->malloc\n");
	}

	path = getenv("PATH");
	for (i = 0; tokens[i]; i++)
	{
		_strcpy(p_cpy, path);
		value = strtok(p_cpy, ":");
		while (value != NULL)
		{
			dir = opendir(value);
			while ((dirc = readdir(dir)) != NULL)
			{
				if (_strcmp(dirc->d_name, tokens[i]) == 0)
				{
					value = _strcat(value, "/");
					tokens[i] = _strcat(value, tokens[i]);
					free(p_cpy);
					return (0);
				}
			}
			value = strtok(NULL, ":");
			if ((closedir(dir)) == -1)
			{
				perror("Error:");
			}
		}
	}
	free(p_cpy);

	return (1);
}
