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

	if (tokens[1] != NULL)
	{
		if (_strncmp(tokens[1], "-", 1) == 0)
		{
			cd_prev(env);
		}
		else
		{
			cwd = _getcwd(env);
			_setenv("OLDPWD", cwd, env);
			free(cwd);
			if (chdir(tokens[1]) == -1)
			{
				perror(tokens[1]);
			}

			cwd = _getcwd(env);
			_setenv("PWD", cwd, env);
			free(cwd);
		}
	}
	else
	{
		cd_home(env);
	}

	return (0);
}
