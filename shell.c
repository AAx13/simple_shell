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
		prompt();
		/*putstr("$ ");*/

		/* read line */
		line = _read();

		/* split line into tokens */
		tokens = parse(line);

		/* exec commands */
		status = exec(tokens, line);

		xfree(line);
		free(tokens);

	} while (status);

	return (status);
}
