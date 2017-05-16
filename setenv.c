#include "header.h"
#include <stdlib.h>

int _setenv(char *name, char *value)
{
	char *new_env;
	size_t name_len;

	name_len = _strlen(name);
	while (*environ)
	{
		if (_strncmp(*environ, name, name_len) == 0)
		{
			new_env = build_env(name, value);
			*environ = _strdup(new_env);
			free(new_env);
			return (0);
		}
		environ++;
	}
	return (-1);
}
