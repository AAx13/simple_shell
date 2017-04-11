#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

int cmd(char **command, char *line)
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
		if (**command != '\n')
		{
			if (execve(command[0], command, NULL) == -1)
			{
				perror("./simple_shell");
				free(line);
				free(command);
				_exit(status);
			}
			return (status);
		}
	}
	wait(&status);
	status = 1;

	return (status);
}
