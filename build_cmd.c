#include <stdlib.h>
#include <string.h>
#include "header.h"

/**
 * build_cmd - builds full command path from command name.
 * @token: The command passed.
 * @value: The current directory found to have the command file.
 *
 * Return: Full command path.
 */
char *build_cmd(char *token, char *value)
{
	char *cmd_path;
	size_t cmd_len;

	cmd_len = _strlen(value) + _strlen(token) + 2;
	cmd_path = malloc(sizeof(char) * cmd_len);
	if (!cmd_path)
	{
		putstr("Error: b_cmd->malloc\n");
		return (NULL);
	}

	memset(cmd_path, 0, cmd_len);

	cmd_path = _strcat(cmd_path, value);
	cmd_path = _strcat(cmd_path, "/");
	cmd_path = _strcat(cmd_path, token);

	return (cmd_path);
}
