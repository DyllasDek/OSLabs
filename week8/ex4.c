#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/time.h>

int main(){
	size_t mem_size = 1024 * 1024 * 2 * 10;
	int *based;
	struct rusage usage;
	for(int i = 1; i <= 10; i++){
		puts("");
		based = malloc(mem_size*sizeof(int)*i);
		memset(based,0,mem_size*sizeof(int)*i);
		getrusage(RUSAGE_SELF, &usage);
		printf("CPU time: %ld.%061d sec user, %ld.%061d sec system ",
		usage.ru_utime.tv_sec, usage.ru_utime.tv_usec,
		usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
		sleep(1);
	}
	free(based);
	return 0;
}
