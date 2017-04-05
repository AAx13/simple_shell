#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/* simple function to compare strings */
int str_n_cmp(char *str1, char *str2, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}

/* ls command handling */
int ls_cmd(char **parsed, int status)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve("/bin/ls", parsed, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
		return (status);
	}
	wait(&status);

	return (status);
}

/* pwd cmd handling */
int pwd_cmd(char **parsed, int status)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve("/bin/pwd", parsed, NULL) == -1)
		{
			perror("Error");
			return (-1);
		}
		return (status);
	}
	wait(&status);

	return (status);
}

/* env cmd handling */
extern char **environ;
int env_cmd(char **parsed, int status)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve("/usr/bin/env", parsed, environ) == -1)
		{
			perror("Error:");
			return (-1);
		}
		return (status);
	}
	wait(&status);

	return (status);
}

/* exec any commands that might be from stdin */
int exec_cmd(char **parsed, int status)
{
	int i;

	if (str_n_cmp(parsed[0], "\n", 1) == 0)
	{
		free(parsed);
	}
	else if (str_n_cmp(parsed[0], "exit\n", 5) == 0) /* exit command */
	{
		for (i = 0; parsed[i]; i++)
		{
			free(parsed[i]);
		}
		free(parsed);
		_exit(status);
	}
	else if (str_n_cmp(parsed[0], "ls", 2) == 0) /* ls command */
	{
		status = ls_cmd(parsed, status);
		free(parsed);
		return (status);
	}
	else if (str_n_cmp(parsed[0], "pwd", 3) == 0) /* pwd command */
	{
		status = pwd_cmd(parsed, status);
		free(parsed);
		return (status);
	}
	else if (str_n_cmp(parsed[0], "env", 3) == 0 /* env and printenv cmd */
			 || str_n_cmp(parsed[0], "printenv", 8) == 0)
	{
		status = env_cmd(parsed, status);
		free(parsed);
		return (status);
	}
	else
	{
		printf("Error: command not found\n");
	}

	return (status);
}

/* parse line and return array of strings */
char **parse_line(char *command)
{
	char **parsed;
	char *token;
	int i, buf_size;

	buf_size = 32;
	parsed = malloc(sizeof(char *) * buf_size);
	token = strtok(command, " ");
	for (i = 0; token != NULL; i++)
	{
		parsed[i] = token;
		token = strtok(NULL, " \n");
	}
	parsed[i] = NULL;

	return (parsed);
}

/* read line from stdin return that line */
char *get_line(char *command)
{
	size_t len;

	len = 0;
	command = NULL;
	getline(&command, &len, stdin);

	return (command);
}

/* set prompt to look for commands */
int main(void)
{
	int status;
	char *command;
	char **parsed;

	status = 0;
	do {
		printf("shell$ ");

		command = get_line(command);

		parsed = parse_line(command);

		status = exec_cmd(parsed, status);
		free(command);
	}
	while (status >= 0);

	return (0);
}
