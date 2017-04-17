#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define BUFFER 256

/**
 * path_cmd - function will search directories in $PATH environment variable
 * for program passed to our shell.
 * @tokens: Parsed commands passed from stdin.
 *
 * Return: 1 on failure, or 0 on Success.
 */
int path_cmd(char **tokens)
{
	char *path, *value, *p_cpy, *cmd_path;
	struct stat buf;

	p_cpy = malloc(sizeof(char) * BUFFER);
	if (!p_cpy)
	{
		putstr("Error: p_cpy->malloc.\n");
	}

	path = _getenv("PATH");
	_strcpy(p_cpy, path);
	value = strtok(p_cpy, ":");
	while (value != NULL)
	{
		cmd_path = build_cmd(*tokens, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*tokens = _strdup(cmd_path);
			free(cmd_path);
			free(p_cpy);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}
	free(path);
	free(p_cpy);

	return (1);
}
