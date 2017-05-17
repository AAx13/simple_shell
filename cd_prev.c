#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * cd_prev - change to previous directory and update environment variables.
 *
 * Return: 0.
 */
int cd_prev(void)
{
	char *prevdir;
	char *cwd;

	cwd = _getcwd();

	prevdir = _getenv("OLDPWD");
	chdir(prevdir);
	free(prevdir);

	_setenv("OLDPWD", cwd);
	free(cwd);

	cwd = _getcwd();
	_setenv("PWD", cwd);
	free(cwd);

	return (0);
}
