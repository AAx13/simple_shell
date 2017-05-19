#include "header.h"

/**
 * print_env - prints the current environment to stdout.
 * @env: Array of strings containing environment variables.
 *
 * Return: 1 if failed, 0 on success.
 */
int print_env(char **env)
{
	int i;

	if (env == NULL)
		return (1);

	for (i = 0; env[i]; i++)
	{
		putstr(env[i]);
		_putchar('\n');
	}

	return (0);
}
