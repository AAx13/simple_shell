#include "header.h"

/**
 * env_b - prints the current environment to stdout.
 *
 * Return: 1 if failed, 0 on success.
 */
int env_b(void)
{
	int i;

	if (environ == NULL)
	{
		return (1);
	}

	for (i = 0; environ[i]; i++)
	{
		putstr(environ[i]);
		_putchar('\n');
	}

	return (0);
}
