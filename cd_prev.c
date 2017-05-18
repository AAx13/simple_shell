#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * cd_prev - change to previous directory and update environment variables.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: 0.
 */
int cd_prev(char **env)
{
	char *prevdir;
	char *cwd;

	cwd = _getcwd(env);

	prevdir = _getenv("OLDPWD");
	chdir(prevdir);
	free(prevdir);

	_setenv("OLDPWD", cwd, env);
	free(cwd);

	cwd = _getcwd(env);
	_setenv("PWD", cwd, env);
	free(cwd);

	return (0);
}
