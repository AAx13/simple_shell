#include <stdio.h>
#include <stdlib.h>
#include "header.h"

/**
 * main - function to loop through each command passed from stdin.
 *
 * Return: 0 on Success.
 */
int main(void)
{
	char **tokens;
	char *new_env[50];
	char *line;
	int status, i;

	status = 1;
	/* build array of environment variables */
	for (i = 0; environ[i]; i++)
		new_env[i] = _strdup(environ[i]);
	new_env[i] = NULL;

	do {
		/* print prompt */
		putstr("$ ");

		/* read line */
		line = _read(new_env);

		/* split line into tokens */
		tokens = parse(line);

		/* handle exit built in */
		if (_strncmp(tokens[0], "exit", 4) == 0)
		{
			status = 0;
			if (tokens[1] != NULL)
				status = _atoi(tokens[1]);
			putstr("[ Exiting ]\n");
		}
		else
		{
			/* exec commands */
			status = exec(tokens, line, new_env);
		}
		free(line);
		free(tokens);

	} while (status == 1);
	free_env(new_env);
	return (status);
}
