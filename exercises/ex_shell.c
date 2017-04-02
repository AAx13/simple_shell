#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* this function will print a prompt and wait for user input
 * afterwards printing from user input
 */
int main(void)
{
	char *line;
	size_t len;
	ssize_t read;

	/*
	 *if line = NULL, getline will allocate enough space to store line
	 * passed from stdin and ignores len in the process
	 */
	line = NULL;
	len = 0;

	do
	{
		/* prints prompt */
		printf("$ ");

		read = getline(&line, &len, stdin);

		/* prints line from stdin to stdout */
		printf("%s", line);

	}
	while (read != -1);

	free(line);
	return (0);
}
