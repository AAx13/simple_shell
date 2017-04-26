#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

/**
 * parse - function that splits the line from stdin.
 * @line: String passed from stdin.
 *
 * Return: Array of strings (parsed line from stdin).
 */
char **parse(char *line)
{
	char **tokens;
	char *token;
	int i, len;

	len = 0;
	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ' || line[i] == '\n')
		{
			len++;
		}
	}
	len++;

	tokens = malloc(sizeof(char *) * len);
	if (!tokens)
	{
		putstr("Error: malloc - parse_line\n");
		return (NULL);
	}

	token = strtok(line, DELIM);
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;

	return (tokens);
}
