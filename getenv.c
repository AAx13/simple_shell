#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @name: Environment variable.
 *
 * Return: The value of the environment variable if found, else NULL.
 */
char *_getenv(char *name)
{
	size_t namelen;
	size_t valuelen;
	char *value;
	int i, x, j;

	namelen = _strlen(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], namelen) == 0)
		{
			valuelen = _strlen(environ[i]) - namelen;
			value = malloc(sizeof(char) * valuelen);
			if (!value)
			{
				perror("_getenv->malloc");
				return (NULL);
			}

			j = 0;
			for (x = namelen + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
