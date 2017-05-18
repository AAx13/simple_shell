#include "header.h"
#include <stdlib.h>

/**
 * _setenv - updates or adds an environment variable.
 * @name: Variable name.
 * @value: Variable value.
 * @env: Array of strings containing environment variables.
 *
 * Return: 0 on success otherwise -1.
 */
int _setenv(char *name, char *value, char **env)
{
	size_t name_len;
	char *new_var;
	int i;

	name_len = _strlen(name);
	for (i = 0; env[i]; i++)
	{
		if (_strncmp(env[i], name, name_len) == 0)
		{
			new_var = build_var(name, value);
			free(env[i]);
			env[i] = _strdup(new_var);
			free(new_var);
			return (0);
		}
	}

	new_var = build_var(name, value);
	free(env[i]);
	env[i] = _strdup(new_var);
	env[++i] = NULL;
	free(new_var);

	return (0);
}
