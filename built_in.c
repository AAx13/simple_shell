#include "header.h"
#include <stdlib.h>

/**
 * built_in - handles built-in programs.
 * @tokens: Parsed line from stdin.
 * @env: Array of strings holding all environment variables.
 *
 * Return: 1 if failed, 0 otherwise.
 */
int built_in(char **tokens, char **env)
{
	if (_strcmp(*tokens, "env") == 0)
	{
		return (print_env(env));
	}
	else if (_strncmp(*tokens, "cd", 2) == 0)
	{
		return (_cd(tokens, env));
	}
	else if (_strcmp(*tokens, "setenv") == 0)
	{
		if (tokens[1] && tokens[2])
		{
			_setenv(tokens[1], tokens[2], env);
			return (0);
		}
		putstr("Usage: setenv VARIABLE VALUE\n");
		return (0);
	}
	else if (_strcmp(*tokens, "unsetenv") == 0)
	{
		if (tokens[1])
		{
			_unsetenv(tokens[1], env);
			return (0);
		}
		putstr("Usage: unsetenv VARIABLE\n");
		return (0);
	}

	return (1);
}
