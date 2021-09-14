#include <stdio.h>
#include <stdlib.h>
int main()
{
  pid_t pid;
  int n = 10;
  for(int i = 0; i < n; i++){
  	switch(pid=fork()) {
  	case 0:
        	  printf("Hello from child [%d - %d]\n", getpid(), i);
        	  break;
        	  exit(0);
  	default:
        	  printf("Hello from parrent[%d - %d]\n", getpid(), i);
        	  wait();
        	  break;
  	}
  }
}
