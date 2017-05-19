#include <sys/stat.h>
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
	struct stat st;

	/* fill st buffer with stdin info */
	if (fstat(0, &st) == -1)
		perror("fstat");

	/* build array of environment variables */
	for (i = 0; environ[i]; i++)
		new_env[i] = _strdup(environ[i]);
	new_env[i] = NULL;

	status = 1;
	do {
		/* if not piped command then print prompt */
		if (!S_ISFIFO(st.st_mode))
		{
			/* print prompt */
			prompt(new_env);
		}

		/* read line */
		line = _read(new_env);

		/* split line into tokens */
		tokens = parse(line);

		/* handle exit built in */
		if (_strncmp(tokens[0], "exit", 4) == 0)
		{
			exit_shell(tokens, line, new_env);
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
