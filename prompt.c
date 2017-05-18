#include <stdlib.h>
#include "header.h"

/**
 * prompt - prints the shell prompt.
 * @env: Array of strings containing envirionment variables.
 *
 * Return: Void.
 */
void prompt(char **env)
{
	char *prompt;

	putstr(prompt = _getenv("USER"));
	free(prompt);
	putstr(":");
	putstr(prompt = _getcwd(env));
	free(prompt);
	putstr("$ ");
}
