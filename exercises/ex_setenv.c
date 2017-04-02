#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char**environ;
int _setenv(const char *name, const char *value, int overwrite)
{
	unsigned int i;
	size_t len;
	char *str_val;


	str_val = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));
	len = strlen(name) + strlen(value) + 2;
	for (i = 0; i < len; i++, str_val++)
	{
		if (*name)
		{
			*str_val = *name;
			name++;
		}
		else if (*value)
		{
			*str_val = *value;
			value++;
		}
	}
	*str_val = '\0';
	str_val -= len;

	putenv(str_val);

	return (overwrite);
}

int main(void)
{
	int i;
	const char *new_path;
	const char *path_value;

	new_path = "DAMIAN_PATH";
	path_value = "THIS IS A TEST";

	/* set env (no overwrite) */
	i = _setenv(new_path, path_value, 0);

	if (i < 0)
	{
		printf("Error");
		return (1);
	}

	/* print env */
	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}

	return (0);
}
