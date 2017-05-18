#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * _read - function to retreive the string (command) from stdin.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: line retreived from stdin.
 */
char *_read(char **env)
{
	char *line;
	size_t len;

	len = 0;
	line = NULL;
	if (getline(&line, &len, stdin) == -1)
	{
		putstr("\n[ Exiting ]\n");
		free(line);
		free_env(env);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
