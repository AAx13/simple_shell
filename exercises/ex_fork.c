#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	my_pid = getpid();
	child_pid = fork();
	printf("My pid is %u and child pid is %u\n", my_pid, child_pid);
	return (0);
}
