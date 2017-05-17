#include <unistd.h>
#include <stdlib.h>
#include "header.h"

/**
 * cd_home - changes directory to home as well as updates environment vars.
 *
 * Return: 0.
 */
int cd_home(void)
{
	char *home;
	char *cwd;

	cwd = _getcwd();
	_setenv("OLDPWD", cwd);
	free(cwd);

	home = _getenv("HOME");
	chdir(home);
	free(home);

	cwd = _getcwd();
	_setenv("PWD", cwd);
	free(cwd);

	return (0);
}
