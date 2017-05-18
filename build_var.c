#include "header.h"
#include <stdlib.h>

/**
 * build_var - builds a full environment variable from given name and value.
 * @name: Variable name.
 * @value: Variable value.
 *
 * Return: String containing full environment variable.
 */
char *build_var(char *name, char *value)
{
	char *new_var;
	size_t var_len;

	var_len = _strlen(name) + _strlen(value) + 2;
	new_var = malloc(sizeof(char) * var_len);
	if (!new_var)
	{
		putstr("Error: build_var->malloc\n");
		return (NULL);
	}

	_memset(new_var, 0, var_len);

	new_var = _strcat(new_var, name);
	new_var = _strcat(new_var, "=");
	new_var = _strcat(new_var, value);

	return (new_var);
}
