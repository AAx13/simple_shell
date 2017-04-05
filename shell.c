#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
	ssize_t _read;
	size_t len;
	char **tokens;
	char *line;
	int status;

	status = 1;
	len = 0;
	line = NULL;
	do {
		/* print prompt */
		putstr("shell$ ");

		/* read line */
		_read = getline(&line, &len, stdin);
		if (_read == -1)
		{
			putstr("\nExiting...\n");
			free(line);
			return (0);
		}

		/* split line into tokens */
		tokens = parse(line);

		/* exec commands */
		status = exec(tokens, line);

		free(tokens);

	} while (status);

	free(line);
	return (0);
}
