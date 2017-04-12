#include "header.h"

/**
 * _strcpy - copies the string (src) to the string (dest).
 * @dest: The copy destination.
 * @src: The copy source.
 *
 * Return: The copied string.
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
