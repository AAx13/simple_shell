#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

/**
 * path_cmd - function will search directories in $PATH environment variable
 * for program passed to our shell.
 * @tokens: Parsed commands passed from stdin.
 *
 * Return: 1 on failure, or 0 on Success.
 */
int path_cmd(char **tokens)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build_cmd(*tokens, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*tokens = _strdup(cmd_path);
			free(path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}

	free(path);
	return (1);
}
