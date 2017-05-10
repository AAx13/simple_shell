#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * exit_b - exits the program when "exit" command is found.
 * @tokens: Parsed commands from stdin.
 * @line: Original line from stdin.
 *
 * Return: Void.
 */
void exit_b(char **tokens, char *line)
{
	int status;

	status = 0;
	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
	}
	free(line);
	free(tokens);
	exit(status);
}
