#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	size_t mem_size = 1024 * 1024 * 2 * 10;
	int *based;
	for(int i = 1; i <= 10; i++){
		based = malloc(mem_size*sizeof(int)*i);
		memset(based,0,mem_size*sizeof(int)*i);
		sleep(1);
	}
	free(based);
	return 0;
}
