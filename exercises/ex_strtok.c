#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char line[] = "Crawwwwling in my skiiiiin these words";
	char *lines[6];
	char *word;
	int i;

	i = 0;
	word = strtok(line, " ");
	while (word != NULL)
	{
		lines[i] = word;
		word = strtok(NULL, " ");
		i++;
	}

	for (i = 0; i < 6; i++)
	{
		printf("%s\n", lines[i]);
	}

	return (0);
}
