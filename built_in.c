#include "header.h"
#include <stdlib.h>

/**
 * built_in - handles built-in programs.
 * @tokens: Parsed line from stdin.
 * @line: Original line from stdin.
 *
 * Return: 1 if failed, 0 otherwise.
 */
int built_in(char **tokens, char *line)
{
	if (_strcmp(*tokens, "exit") == 0)
	{
		exit_b(tokens, line);
	}
	else if (_strcmp(*tokens, "env") == 0)
	{
		return (env_b());
	}
	else if (_strcmp(*tokens, "setenv") == 0)
	{
		return (setenv(tokens[1], tokens[2], 1));
	}
	else if (_strcmp(*tokens, "unsetenv") == 0)
	{
		return (unsetenv(tokens[1]));
	}
	else if (_strcmp(*tokens, "cd") == 0)
	{
		return (_cd(tokens));
	}

	return (1);
}
