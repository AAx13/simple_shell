#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/* This function will execute ls -l on /tmp dir 5 times run by the same parent process. */
int main(void)
{
	pid_t pid;
	pid_t parent;
	int status;
	char *ls[] = {"/bin/ls", "-l", "/tmp", NULL};

	status = 1;
	parent = getpid();

	pid = fork();
	if (pid == -1)
	  {
	    perror("Error");
	    return (-1);
	  }
	
	if (pid == 0)
	  {
	    printf("Child Process is %u | Parent is %u\n", getpid(), parent);
	    execve(ls[0], ls, NULL);
	  }

	wait(&status);
	
	return (0);
}
