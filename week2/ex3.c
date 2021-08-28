#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int space = n - 1;	
	for (int i = 0; i < n; i++){
		for (int a = 0; a < space; a++){
			printf(" ");
		}
		for (int o = 0; o < 1 + 2*i; o++){
			printf("*");
		}
		for (int a = 0; a < space; a++){
			printf(" ");
		}
		printf("\n");
		space--;
		}
	return 0;
}
