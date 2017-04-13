#include "header.h"

int built_in(char **tokens, char *line)
{
	if (_strcmp(*tokens, "exit") == 0)
	{
		exit_b(tokens, line);
	}
	else if (_strcmp(*tokens, "env") == 0)
	{
		env_b();
		return (0);
	}

	return (1);
}
