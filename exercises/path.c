#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#define BUFFER 512

int path_cmd(char **tokens __attribute__((unused)))
{
	char *path, *value, *p_cpy, *full_dir;
	size_t dir_len;
	struct stat sb;

	p_cpy = malloc(sizeof(char) * BUFFER);
	if (!p_cpy)
	{
		putstr("Error: p_cpy->malloc.\n");
	}

	path = getenv("PATH");
	_strcpy(p_cpy, path);
	value = strtok(p_cpy, ":");
	while (value != NULL)
	{
		full_dir = malloc(sizeof(char) * (_strlen(value) + _strlen(tokens[0]) + 2));
		full_dir = _strcat(value, "/");
		full_dir = _strcat(full_dir, tokens[0]);
		dir_len = (_strlen(value) + _strlen(tokens[0]));
		full_dir[dir_len + 2] = '\0';
		if (stat(full_dir, &sb) == 0)
		{
			tokens[0] = full_dir;
			putstr(tokens[0]);
			return (0);
		}
		value = strtok(NULL, ":");
	}
	free(p_cpy);

	return (0);
}
