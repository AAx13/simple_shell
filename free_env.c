#include <stdlib.h>
#include "header.h"

/**
 * free_env - frees an array of strings containing env variables.
 * @env: Array of strings containing environment variables.
 *
 * Return: Void.
 */
void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		free(env[i]);
	}
}
