#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#define BUFFER 128

/* this function is like "which" command for the $PATH env variable */
int main(int ac, char **av)
{
	char *path, *value, *p_cpy;
	struct dirent *dirc;
	DIR *dir;
	int i, sentinel;

	if (ac < 2)
	{
		printf("Usage: ./_which filename ...\n");
		return (1);
	}

	p_cpy = malloc(sizeof(char) * BUFFER);
	if (!p_cpy)
	{
		printf("Error: p_cpy->malloc\n");
	}

	sentinel = 0;
	path = getenv("PATH");
	for (i = 1; i < ac; i++)
	{
		strcpy(p_cpy, path);
		value = strtok(p_cpy, ":");
		while (value != NULL)
		{
			dir = opendir(value);
			while ((dirc = readdir(dir)) != NULL)
			{
				if (strcmp(dirc->d_name, av[i]) == 0)
				{
					printf("%s/%s\n", value, av[i]);
					sentinel++;
				}
			}
			value = strtok(NULL, ":");
			if ((closedir(dir)) == -1)
			{
				perror("Error:");
			}
		}
		if (sentinel == 0)
		{
			printf("%s: filename does not exist.\n", av[i]);
		}
		sentinel = 0;
	}
	free(p_cpy);
	return (0);
}
