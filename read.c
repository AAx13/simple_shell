#include <stdio.h>
#include <stdlib.h>
#include "header.h"

char *_read(void)
{
	char *line;
	size_t len;

	len = 0;
	line = NULL;
	if (getline(&line, &len, stdin) == -1)
	{
		putstr("\n[ Exiting ]\n");
		free(line);
		exit(EXIT_SUCCESS);
	}

	return (line);
}
