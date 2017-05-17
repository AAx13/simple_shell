#include <stdlib.h>
#include "header.h"

/**
 * _unsetenv - remove an environment variable.
 * @name: Name of the environment variable to remove.
 *
 * Return: 0 if successful or -1 if unsuccessful.
 */
int _unsetenv(char *name)
{
	char **new_env;
	size_t name_len;
	int env_len;
	int i, x;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0)
		{
			x = i;
		}
	}

	env_len = i;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
	{
		perror("malloc->unsetenv");
		return (-1);
	}

	for (i = 0; i < env_len; i++)
	{
		if (i != x)
		{
			new_env[i] = environ[i];
		}
	}
	new_env[i] = NULL;

	environ = new_env;

	free(new_env);
	return (0);
}
