#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

extern char **environ;
int exec(char **tokens, char *line)
{
	int status;
	pid_t pid;

	if (*tokens == NULL)
	{
		return (1);
	}

	path_cmd(tokens);

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (execve(*tokens, tokens, environ) == -1)
		{
			perror("Error");
			free(line);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);

	return (1);
}
