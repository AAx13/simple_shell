#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * _cd - handles the change directory built-in function.
 * @tokens: The parsed command line from stdin.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int _cd(char **tokens, char **env)
{
	char *cwd;

	if (tokens[1] == NULL)
	{
		cd_home(env);
	}
	else
	{
		if (_strcmp(tokens[1], "-") == 0)
		{
			cd_prev(env);
		}
		else
		{
			cwd = _getcwd();
			_setenv("OLDPWD", cwd, env);
			free(cwd);
			if (chdir(tokens[1]) == -1)
			{
				perror(tokens[1]);
			}

			cwd = _getcwd();
			_setenv("PWD", cwd, env);
			free(cwd);
		}
	}

	return (0);
}
