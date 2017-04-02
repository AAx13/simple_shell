#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

/* this function gets value of an environment variable and returns it */
char *_getenv(const char *name)
{
	unsigned int i;

	for (i = 0; environ[i]; i++)
	{
		if (strcmp(name, strtok(environ[i], "=")) == 0)
		{
			return (strtok(NULL, ""));
		}
	}
	return ("No var by that name exists");
}

int main(void)
{
	const char *name;

	name = "LS_COLORS";

	printf("%s\n", _getenv(name));

	return (0);
}
