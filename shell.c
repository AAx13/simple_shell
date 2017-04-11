#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
	char **tokens;
	char *line;
	int status;

	status = 1;
	line = NULL;
	do {
		/* print prompt */
		putstr("shell$ ");

		/* read line */
		line = _read();

		/* split line into tokens */
		tokens = parse(line);

		/* exec commands */
		status = exec(tokens, line);

		free(line);
		free(tokens);

	} while (status);

	return (status);
}
