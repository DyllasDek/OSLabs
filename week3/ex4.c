#include <stdio.h>
#include <stdlib.h>
void quick_sort(int array[], int size) {
    int i = 0;
    int j = size - 1;
    int mid = array[size / 2];

    do{
        while(array[i] < mid) {i++;}
        while(array[j] > mid) {j--;}
        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    } while (i <= j);
    if(j > 0) {
        quick_sort(array, j + 1);
    }
    if (i < size) {
        quick_sort(array, size - i);
    }
}



void bubble_sort(int array[], int size){
	int a,b, temp;
	for (a = 0; a < size - 1; a++){
		for (b = 0; b < size - a - 1; b++){
			if (array[b] > array[b+1]){
				temp = array[b];
				array[b] = array[b+1];
				array[b+1] = temp;
			}
		}
	}
}

int main(){
	puts("Write size of the array");
	
	char string[256];
	fgets (string,256,stdin);
	int n = atoi(string);
	
	int* array = malloc(n*sizeof(int));
	puts("Now write integer elements of array");
	
	for (int i = 0; i < n; i++){
		scanf("%d",&array[i]);
	}
	puts("\n");
	
	quick_sort(array,n);
	
	puts("Here is your sorted array:");
	for (int i = 0; i < n; i++){
		printf("%d ",array[i]);
	}
	puts("\n");
	
	free(array);
	return 0;
}
