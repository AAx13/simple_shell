#include "header.h"

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
