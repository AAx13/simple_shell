#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

extern char **environ;
int exec(char **tokens)
{
	int status;
	pid_t pid;

	status = 1;
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (**tokens != '\n')
		{
			if (execve(tokens[0], tokens, environ) == -1)
			{
				perror("./simple_shell");
				free(tokens);
				_exit(status);
			}
			return (status);
		}
	}
	wait(&status);
	status = 1;

	return (status);
}
