#include "header.h"
#include <stdlib.h>

/**
 * build_env - builds a full environment variable from given name and value.
 * @name: Variable name.
 * @value: Variable value.
 *
 * Return: String containing full environment variable.
 */
char *build_env(char *name, char *value)
{
	char *new_env;
	size_t env_len;

	env_len = _strlen(name) + _strlen(value) + 2;
	new_env = malloc(sizeof(char) * env_len);
	if (!new_env)
	{
		putstr("Error: build_env->malloc\n");
		return (NULL);
	}

	_memset(new_env, 0, env_len);

	new_env = _strcat(new_env, name);
	new_env = _strcat(new_env, "=");
	new_env = _strcat(new_env, value);

	return (new_env);
}
