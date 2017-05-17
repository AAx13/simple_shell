#include "header.h"
#include <stdlib.h>

int _setenv(char *name, char *value)
{
	char *new_env;
	size_t name_len;
	int i;

	name_len = _strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0)
		{
			new_env = build_env(name, value);
			_strcpy(environ[i], new_env);
			free(new_env);
			return (0);
		}
	}
	return (-1);
}
