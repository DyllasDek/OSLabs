#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *ThreadCheck(void *thread_data){
	int *id = (int *)thread_data;
	printf("Hi from thread: %d\n",id);
	puts("I've terminated thread");
	pthread_exit(0);
}

int main(){
pthread_t thread;
for (int i = 0; i < 10; i++){
	int id;
	puts("I've created a thread");
	pthread_create(&thread,NULL,ThreadCheck,i+1);
	pthread_join(thread,NULL);
}
}
