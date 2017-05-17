#include "header.h"
#include <stdlib.h>

/**
 * _setenv - updates or adds an environment variable.
 * @name: Variable name.
 * @value: Variable value.
 *
 * Return: 0 on success otherwise -1.
 */
int _setenv(char *name, char *value)
{
	size_t name_len;
	char **new_env;
	char *new_var;
	int i;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0)
		{
			new_var = build_env(name, value);
			_strcpy(environ[i], new_var);
			free(new_var);
			return (0);
		}
	}

	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
	{
		perror("malloc->setenv");
		return (-1);
	}

	for (i = 0; environ[i]; i++)
	{
		new_env[i] = environ[i];
	}
	new_var = build_env(name, value);
	new_env[i] = new_var;
	new_env[i + 1] = NULL;

	environ = new_env;

	free(new_var);
	free(new_env);
	return (0);
}
