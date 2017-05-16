#include "header.h"
#include <stdlib.h>

/**
 * built_in - handles built-in programs.
 * @tokens: Parsed line from stdin.
 *
 * Return: 1 if failed, 0 otherwise.
 */
int built_in(char **tokens)
{
	if (_strcmp(*tokens, "env") == 0)
	{
		return (env_b());
	}
	else if (_strncmp(*tokens, "cd", 2) == 0)
	{
		return (_cd(tokens));
	}

	return (1);
}
