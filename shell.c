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
	char *line;
	int status;

	status = 1;
	do {
		/* print prompt */
		/*prompt();*/
		putstr("$ ");

		/* read line */
		line = _read();

		/* split line into tokens */
		tokens = parse(line);

		/* handle exit built in */
		if (_strncmp(*tokens, "exit", 4) == 0)
		{
			status = 0;
			if (tokens[1] != NULL)
			{
				status = _atoi(tokens[1]);
			}
			putstr("[ Exiting ]\n");
		}
		else
		{
			/* exec commands */
			status = exec(tokens, line);
		}

		free(line);
		free(tokens);

	} while (status == 1);

	return (status);
}
