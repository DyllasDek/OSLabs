#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
	char string[256];
	puts("Input your string:");
	fgets (string,256,stdin);
	string[strlen(string)-1] = "\0";
	puts(":gnirts desrever ruoy si ereH");
	for (int i = strlen(string); i >= 0; i--){
		putchar(string[i]);
	}	
	puts("\0");
	return 0;
}
