#include <stdio.h>
#include "header.h"

/**
 * _strcat - concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: The concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	size_t i;
	size_t len;

	len = _strlen(dest);
	for (i = 0; src[i]; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = '\0';

	return (dest);
}
