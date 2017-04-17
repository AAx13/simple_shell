#include <stdlib.h>
#include "header.h"

void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	size_t i;

	if (size == 0 || !ptr)
	{
		return (NULL);
	}

	new_ptr = malloc(size);

	for (i = 0; ptr[i]; i++);

	if (size <= i || !new_ptr)
	{
		putstr("Error: realloc\n");
		return (ptr);
	}

	for (i = 0; i < size; i++)
	{
		new_ptr[i] = ptr[i];
	}

	return (new_ptr);
}
