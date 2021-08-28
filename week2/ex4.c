#include <stdlib.h>
#include <stdio.h>

void swap (int *a, int *b){
	int sw;
	sw = *a;
	*a = *b;
	*b = sw;
}


int main(){
	int first,second;
	char input[256];
	
	puts("Input two integers:");
	printf("1st:");
	fgets (input,256,stdin);
	first = atoi(input);
	
	printf("2nd:");
	fgets (input,256,stdin);
	second = atoi(input);
	
	swap(&first,&second);
	
	printf("Here is your swaped numbers:\n1st:%d, 2nd:%d\n",first,second);

		
}
