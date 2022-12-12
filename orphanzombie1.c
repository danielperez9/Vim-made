#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
int main  ()
{
	//fork returns process id 
	//in parent process
	pid_t pid =fork();
	if(pid >0 )//parent process
	{
		printf("Parent pid:  %d\n", getpid());
		sleep(50);
	}
	else
	{
		printf ("child pd:  %d\n", getpid());
		exit(0); //child proces
	}
	return 0;
}
