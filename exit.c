#include <stdlib.h>
#include "header.h"

void exit_b(char **tokens, char *line)
{
	int status;

	status = 0;
	if (tokens[1] != NULL)
	{
		status = _atoi(tokens[1]);
	}
	free(line);
	free(tokens);
	exit(status);
}
