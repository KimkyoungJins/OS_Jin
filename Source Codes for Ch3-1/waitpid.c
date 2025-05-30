#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define N 5

int main() 
{
    pid_t pid[N];
    int i;
    int child_status;
    for (i = 0; i < N; i++)
		if ((pid[i] = fork()) == 0)
	    	exit(100+i); /* Child */
    for (i = 0; i < N; i++) {
		pid_t wpid = waitpid(pid[i], &child_status, 0);
		if (WIFEXITED(child_status))
			printf("Child %d terminated with exit status %d\n",
					wpid, WEXITSTATUS(child_status));
		else
			printf("Child %d terminated abnormally\n", wpid);
    }
}
