#include <stdio.h>

/* This function prints address of environ variable as well as env */
extern char**environ;
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
	/* they both hold the same address */
	printf("%p\n", (void *)environ);
	printf("%p\n", (void *)env);

	return (0);
}
