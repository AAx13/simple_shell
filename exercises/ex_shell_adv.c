#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER 128

char *parse(char *line)
{
	int c, i;

	i = 0;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		line[i] = c;
		i++;
	}
	return (line);
}

int main(void)
{
	int status;
	char *line;

	line = malloc(sizeof(char) * BUFFER);
	status = 1;
	do
	{
		printf("$ ");
		line = parse(line);
		printf("%s\n", line);
	}
	while (status);

	return (0);
}
