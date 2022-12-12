/*exec.c*/

#include <stdio.h>

/* this program forks and  and then prints wheather the proccess is 
 *   - the child (the return value of fork() is 0), or 
 *   - the parent (the return value of fork () is not zero)
 * Note, if you juxtapose two strings, the compiler automatically
 * concatenates the two , e.g., "Hello" "world!"
 */

int main(void)
{
	char *argv[]={"ls", "-lart","/home",NULL};
	int pid = fork();
	if (pid == 0 ) {
		execvp( "ls",argv);
	}
	/* Put the parent to sleep for seconds --let the child finished executing*/
//	wait(2);
	printf("finished executing the parent process\n"
			" -the child won't get here-- you will only see this onece\n");
	return 0;
}
