#include <unistd.h>
#include <stdlib.h>
#include "header.h"

/**
 * _cd - handles the change directory built-in function.
 * @tokens: The parsed command line from stdin.
 *
 * Return: 0.
 */
int _cd(char **tokens)
{
	char *home;
	char *cwd;

	cwd = _getcwd();
	_setenv("OLDPWD", cwd);
	free(cwd);

	if (tokens[1] == NULL)
	{
		home = _getenv("HOME");
		chdir(home);
		free(home);
	}
	else if (chdir(tokens[1]) == -1)
	{
		perror(tokens[1]);
	}

	cwd = _getcwd();
	_setenv("PWD", cwd);
	free(cwd);

	return (0);
}
