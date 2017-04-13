#include "header.h"

/**
 * env_b - prints the current environment to stdout.
 *
 * Return: Void.
 */
void env_b(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		putstr(environ[i]);
		_putchar('\n');
	}
}
