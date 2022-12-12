#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	//create a chid process
	int pid =fork();
	if (pid>0)
		printf("in parent process, pid: %d\n", pid);
	//note that pid is 0 in child process
	//and negative if fork() falls
	else if (pid==0) 
	{
		sleep(30);
	printf("in child process, pid:  %d\n");
	}
	return 0;
}
