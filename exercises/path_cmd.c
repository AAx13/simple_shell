#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "header.h"
#define BUFFER 256

/**
 * path_cmd - function will search directories in $PATH environment variable
 * for program passed to our shell.
 * @tokens: Parsed commands passed from stdin.
 *
 * Return: EXIT_FAILURE or 0 on Success.
 */
int path_cmd(char **tokens)
{
	char *path, *value, *p_cpy;
	struct dirent *dirc;
	DIR *dir;
	int i;

	p_cpy = malloc(sizeof(char) * BUFFER);
	path = _get_path();
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
					closedir(dir);
					free(path);
					free(p_cpy);
					return (1);
				}
			}
			value = strtok(NULL, ":");
			if ((closedir(dir)) == -1)
			{
				perror("Error");
				return (EXIT_FAILURE);
			}
		}
	}
	free(path);
	free(p_cpy);
	return (0);
}
