#include <stdio.h>
#include "header.h"

size_t _strlen(char *str)
{
	size_t i;

	for (i = 0; str[i]; i++);

	return (i);
}
