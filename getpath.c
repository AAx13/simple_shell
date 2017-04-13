#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#define BUFFER 256

/**
 * _getpath - Gets the $PATH from the environment.
 *
 * Return: The value of $PATH.
 */
char *_getpath(void)
{
	char *value;
	unsigned int i, j;

	value = malloc(sizeof(char) * BUFFER);
	if (!value)
	{
		putstr("Error get_path->malloc\n");
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp("PATH=", environ[i], 5) == 0)
		{
			break;
		}
	}

	for (j = 5; j < BUFFER; j++)
	{
		value[j - 5] = environ[i][j];
	}

	return (value);
}
