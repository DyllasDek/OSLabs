#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void first_type(int n){
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
}

void second_type(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
}

void third_type(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-2; i >= 0; i--){
		for (int j = 0; j <= i; j++){
			printf("*");
		}
		printf("\n");
	}
}

void fourth_type(int n){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	switch (atoi(argv[2])){
	case 1:
		first_type(n);
		break;
	case 2:
		second_type(n);
		break;
	case 3:
		third_type(n);
		break;
	case 4:
		fourth_type(n);
		break;
	}
	
	return 0;
}
