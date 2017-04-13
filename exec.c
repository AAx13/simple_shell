#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"

/**
 * exec - function to execute commands from stdin.
 * @tokens: The parsed line from stdin.
 * @line: The original line from stdin.
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE.
 */
int exec(char **tokens, char *line)
{
	int status;
	pid_t pid;

	if (*tokens == NULL || built_in(tokens, line) == 0)
	{
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		if (_strncmp(*tokens, "./", 2) != 0)
		{
			path_cmd(tokens);
		}

		if (execve(*tokens, tokens, environ) == -1)
		{
			perror(*tokens);
			free(line);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);

	return (1);
}
