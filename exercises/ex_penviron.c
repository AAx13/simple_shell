#include <stdio.h>

extern char**environ;
int main(void)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (0);
}
