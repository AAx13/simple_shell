#include <stdio.h>
#include <string.h>

/* this function prints all directories in PATH environment variable */
void print_path(char **env)
{
	unsigned int i;
	char *dir;

	for (i = 0; env[i]; i++)
	{
		if (strcmp("PATH", strtok(env[i], "=")) == 0)
		{
			dir = strtok(NULL, ":");
			while (dir != NULL)
			{
				printf("%s\n", dir);
				dir = strtok(NULL, ":");
			}
		}
	}
}

int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	print_path(env);

	return (0);
}
