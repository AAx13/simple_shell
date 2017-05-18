#include <unistd.h>
#include <stdlib.h>
#include "header.h"

/**
 * cd_home - changes directory to home as well as updates environment vars.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int cd_home(char **env)
{
	char *home;
	char *cwd;

	cwd = _getcwd(env);
	_setenv("OLDPWD", cwd, env);
	free(cwd);

	home = _getenv("HOME");
	chdir(home);
	free(home);

	cwd = _getcwd(env);
	_setenv("PWD", cwd, env);
	free(cwd);

	return (0);
}
