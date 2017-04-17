#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"
#define BUFFER 128

/**
 * _getenv - Gets the value of an environment variable.
 * @var: Environment variable.
 *
 * Return: The value of $PATH.
 */
char *_getenv(char *var)
{
	size_t len;
	char *value;
	unsigned int i, j;

	len = _strlen(var);
	value = malloc(sizeof(char) * BUFFER);
	if (!value)
	{
		putstr("Error get_path->malloc\n");
		return (NULL);
	}

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(var, environ[i], len) == 0)
		{
			break;
		}
	}

	for (j = len; j < BUFFER; j++)
	{
		value[j - len] = environ[i][j];
	}

	return (value);
}
