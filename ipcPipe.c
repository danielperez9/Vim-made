#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void)
{
	char write_msg[BUFFER_SIZE] = "Greetings";
	char read_msg[BUFFER_SIZE];
	pid_t pid;
	int fd[2];

	/*Create the pipe*/
	if (pipe(fd) ==-1)
	{
		fprintf(stderr,"Pipe Failed");
		return 1;
	}
	/*npw fork a child process*/
	pid =fork();
	if(pid <0)
	{
		fprintf(stderr, "Fork Failed");
		return 1;
	}
	if (pid>0) 
	{
		/*close the unused end of the pipe*/
		close(fd[READ_END]);
	
		/*write to the pipe*/
		write(fd[WRITE_END], write_msg,strlen(write_msg)+1);
	
		/*close the write end of the pipe*/
		close (fd[WRITE_END]);
	}
	else // child process
	{
		/*child process close the unused end of the pipe*/
		close(fd[WRITE_END]);
		read(fd[READ_END],read_msg, BUFFER_SIZE);
		printf("child read %\n", read_msg);
		/*close and write end of pipe*/
		close(fd[READ_END]);
	}
	return 0;
}

