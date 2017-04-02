#include <stdio.h>
#include <stdlib.h>
#define BUFFER 32

char *_strtok(char *line, const char *delim)
{
	int i;
	static char *left;

	if (line == 0)
	{
		line = left;
	}

	for (i = 0; *line != *delim; i++, line++);

	*line = *(line + i);
	*left = *(line + 1);
	*left = 0;

	return (line);
}

int main(void)
{
	char line[] = "What Is This Crap";
	char *token = _strtok(line, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = _strtok(NULL, " ");
	}

	return (0);
}
