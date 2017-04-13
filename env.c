#include "header.h"

void env_b(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		putstr(environ[i]);
		_putchar('\n');
	}
}
