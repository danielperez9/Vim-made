#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
  //make two porcess which run same
  //program after this instruction
  fork();
  printf("Hello World\n");
  printf("Hello Pid%d\n", getpid());
  return 0;
}


