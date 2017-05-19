#include <stdlib.h>
#include "header.h"

/**
 * exit_shell - exits shell with arguments.
 * @tokens: The parsed line from stdin.
 *
 * Return: Void.
 */
void exit_shell(char **tokens, char *line, char **env)
{
	int status;

	status = 0;
	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
		if (status >= 0)
		{
			free(line);
			free(tokens);
			free_env(env);
			exit(status);
		}
		putstr("exit: Illegal number: ");
		putstr(tokens[1]);
		_putchar('\n');
	}
	else
	{
		free(line);
		free(tokens);
		free_env(env);
		exit(status);
	}
}
