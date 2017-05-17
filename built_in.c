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
		return (print_env());
	}
	else if (_strcmp(*tokens, "setenv") == 0)
	{
		if (tokens[1] && tokens[2])
		{
			_setenv(tokens[1], tokens[2]);
			return (0);
		}
		putstr("Usage: setenv VARIABLE VALUE\n");
		return (0);
	}
	else if (_strcmp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenv(tokens[1]);
			return (0);
		}
		putstr("Usage: unsetenv VARIABLE\n");
		return (0);
	}
	else if (_strncmp(*tokens, "cd", 2) == 0)
	{
		return (_cd(tokens));
	}

	return (1);
}
