#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFFER 32

extern char **environ;
int main(void)
{
	char **tokens;
	char *token;
	ssize_t read;
	char *line;
	size_t len;
	int i;

	len = 0;
	line = NULL;
	while (1)
	{
		printf("> ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			return (0);
		}

		tokens = malloc(sizeof(char *) * BUFFER);
		token = strtok(line, " \n");
		for (i = 0; token; i++)
		{
			tokens[i] = token;
			token = strtok(NULL, " \n");
		}

		token = NULL;
		free(tokens);
	}

	return (0);
}
