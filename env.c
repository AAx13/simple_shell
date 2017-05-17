#include "header.h"

/**
 * print_env - prints the current environment to stdout.
 *
 * Return: 1 if failed, 0 on success.
 */
int print_env(void)
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
