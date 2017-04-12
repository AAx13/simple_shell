#include "header.h"

/**
 * putstr - writes a string to stdout.
 * @str: A string.
 *
 * Return: Amount of bytes writen to stdout excluding null byte.
 */
int putstr(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}
