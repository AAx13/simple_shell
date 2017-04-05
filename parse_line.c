#include <stdlib.h>
#include <string.h>
#include "header.h"
#define BUFFER 32

char **parse_line(char *line)
{
	char **tokens;
	char *token;
	int i;

	tokens = malloc(sizeof(char *) * BUFFER);
	if (!tokens)
	{
		putstr("Error: malloc - parse_line\n");
		return (NULL);
	}

	token = strtok(line, " \n");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;

	return (tokens);
}
