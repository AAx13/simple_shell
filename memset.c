#include "header.h"

/**
 * _memset - fills memory with a constant byte
 * @s: Memory area to initialize.
 * @c: Constant byte.
 * @n: Amount of bytes to initialize.
 *
 * Return: Void.
 */
void _memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *)s + i) = c;
	}
}
