#include <stdlib.h>
#include "header.h"

/**
 * prompt - prints the shell prompt.
 *
 * Return: Void.
 */
void prompt(void)
{
	char *prompt;

	putstr(prompt = _getenv("USER"));
	free(prompt);
	putstr(":");
	putstr(prompt = _getcwd());
	free(prompt);
	putstr("$ ");
}
