#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * _read - function to retreive the string (command) from stdin.
 *
 * Return: line retreived from stdin.
 */
char *_read(void)
{
	char *line;
	size_t len;
	int read;

	len = 0;
	line = NULL;
	read = getline(&line, &len, stdin);
	if (read == -1 || _strncmp(line, "exit", 4) == 0)
	{
		putstr("[ Exiting ]\n");
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
