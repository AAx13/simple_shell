#include <stdio.h>
#include "header.h"

/**
 * _strlen - gets the length of a string excluding the null byte.
 * @str: A string.
 *
 * Return: Length of a string.
 */
size_t _strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		i++;
	}

	return (i);
}
