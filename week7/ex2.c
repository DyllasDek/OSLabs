
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	puts("Size of array:");
	scanf("%d",&N);
	int* arr = (int*)malloc(N * sizeof(int));
	for (int i = 0; i < N; i++) {
	    arr[i] = i + 1;
	}

	printf("Ur array: ");
	for (int i = 0; i < N; i++) {
	    printf("%d ", arr[i]);
	}
	free(arr);
	puts("\nMemory have it's freedom");
	return 0;
}
