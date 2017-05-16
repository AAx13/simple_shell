#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "header.h"

/**
 * _getenv - Gets the value of an environment variable.
 * @var: Environment variable.
 *
 * Return: The value of the environment variable if found, else NULL.
 */
char *_getenv(char *var)
{
	char *env;
	char *value;
	char *token;

	while (*environ)
	{
		env = *environ;
		token = strtok(env, "=");
		if (token)
		{
			if (_strcmp(var, token) == 0)
			{
				token = strtok(NULL, "\0");
				value = token;
				return (value);
			}
		}
		environ++;
	}

	return (NULL);
}
