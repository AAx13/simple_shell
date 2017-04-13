#include "header.h"

void _memset(void *s, int c, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		*((char *)s + i) = c;
	}
}
