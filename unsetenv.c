#include <stdlib.h>
#include "header.h"

/**
 * _unsetenv - remove an environment variable.
 * @name: Name of the environment variable to remove.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0 if successful or -1 if unsuccessful.
 */
int _unsetenv(char *name, char **env)
{
	char **temp_env;
	size_t name_len;

	name_len = _strlen(name);
	while (*env)
	{
		if (_strncmp(*env, name, name_len) == 0)
		{
			temp_env = env;
			free(temp_env[0]);
			do {
				temp_env[0] = temp_env[1];
				temp_env++;

			} while (*temp_env);
		}
		env++;
	}

	return (0);
}
