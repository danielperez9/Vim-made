#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
void* trythis (void* args)
{
	unsigned long i=0;
	counter +=1;// this is the critical code that repeats with the loop 
	// it does not allow the second print statement to print that job 1 is done
	// to fix this we can lock the counter variable until the loop is done then unlock it when it reaches the print statement of "job %d has finished"
	printf("\n job %d has startted \n", counter);
	for(i=0; i<(0xFFFFFFFF); i++)
		;
	printf("\n job %d has finished \n", counter);
	return NULL;
}
int main(void)
{
	int i=0;
	int error;
	while (i<2)
	{
		error =pthread_create(&(tid[i]), NULL, &trythis,NULL);
		if (error !=0)
		{
			printf("\n Thread can't be created : [%s]",strerror(error));
		}
		i++;
	}
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	
	return 0;
}
