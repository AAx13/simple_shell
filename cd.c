#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * _cd - handles the change directory built-in function.
 * @tokens: The parsed command line from stdin.
 *
 * Return: 0.
 */
int _cd(char **tokens)
{
	char *cwd;

	if (tokens[1] == NULL)
	{
		cd_home();
	}
	else
	{
		if (_strcmp(tokens[1], "-") == 0)
		{
			cd_prev();
		}
		else
		{
			cwd = _getcwd();
			_setenv("OLDPWD", cwd);
			free(cwd);
			if (chdir(tokens[1]) == -1)
			{
				perror(tokens[1]);
			}

			cwd = _getcwd();
			_setenv("PWD", cwd);
			free(cwd);
		}
	}

	return (0);
}
