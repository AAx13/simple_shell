#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/cat", "/vagrant/Holberton/simple_shell/exercises/ex_execve.c"};

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error");
	}

	return (0);
}
