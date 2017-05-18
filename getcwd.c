#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "header.h"

/**
 * _getcwd - gets the current working directory.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: Returns a string containing the current working directory.
 */
char *_getcwd(char **env)
{
	char *cwd;
	size_t len;

	environ = env;

	len = PATH_MAX;
	cwd = malloc(sizeof(char) * len);
	if (!cwd)
	{
		putstr("Error: _cd->malloc\n");
		return (NULL);
	}

	if (getcwd(cwd, len) == NULL)
	{
		perror("Error");
		return (NULL);
	}

	return (cwd);
}
