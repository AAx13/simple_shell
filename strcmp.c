#include "header.h"

/**
 * _strcmp - compares two strings.
 * @s1: A string.
 * @s2: A string.
 *
 * Return: 1 if the strings are different 0 if they aren't.
 */
int _strcmp(const char *s1, const char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}

	return (0);
}
