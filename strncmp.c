#include "header.h"

/**
 * _strncmp - compares (n) amount of characters of two strings.
 * @s1: A string.
 * @s2: A string.
 * @n: Amount of characters to compare.
 *
 * Return: 1 if the strings don't match otherwise return 0.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
