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
	setenv("OLDPWD", cwd, 1);

	if (tokens[1] == NULL)
	{
		home = _getenv("HOME");
		chdir(home);
		free(home);
	}
	else
	{
		chdir(tokens[1]);
	}
	free(cwd);

	cwd = _getcwd();
	setenv("PWD", cwd, 1);

	free(cwd);
	return (0);
}
