#include <stdlib.h>
#include <stdio.h>
#include <sys/resource.h>
#include <stdint.h>
#include <limits.h>

typedef struct page{
    int id;
    uint16_t count;
} page;

int N=0;
float miss=0, hit=0;

void C_upd(page frames[], int n){
    for(int i=0; i<n; i++){
        frames[i].count >>=1;
    }
}

int findPage(int pageId, page frames[], int n){
    for(int i=0; i<n; i++){
        if(frames[i].id == pageId) return i;
    }
    return -1;
}

void readPage(int pagePos, page frames[]){
    frames[pagePos].count|=1<<(sizeof(uint16_t)*8-1);
}

void addPage(int pageId, page frames[], int n){
    int pagePos = -1;
    for(int i=0; i<n; i++){
        if(frames[i].id == -1){
            pagePos = i;
        }
    }
    if(pagePos!=-1){
        frames[pagePos].id = pageId;
        readPage(pagePos, frames);
    }
    else {
        unsigned int minAge = UINT16_MAX;
        for(int i=0; i<n; i++){
            if(minAge>=frames[i].count){
                minAge = frames[i].count;
                pagePos = i;
            }
        }
        frames[pagePos].id = pageId;
        frames[pagePos].count = 0;
        readPage(pagePos, frames);
    }
}

int main(){
    scanf("%d", &N);
    page frames[N];
    FILE* input = fopen("Lab 09 input.txt", "r");
    FILE* output = fopen("ex1_o.txt","w");
    int id;
    int num =0;
    
    for (int i=0; i<N; i++){
        frames[i].id = -1;
        frames[i].count = 0;
    }

    while(!feof(input)){
    	num = fscanf(input, "%d", &id);
        if(num == 1){
		for(int i=0; i<N; i++){
		  fprintf(output, "i = %d  id = %d  %d\n", i, frames[i].id, frames[i].count);
		}
		fprintf(output, "current page number %d\n\n", id);
	     
		C_upd(frames, N);

		int pos = findPage(id, frames, N);
		if(pos != -1){
		    hit++;
		    readPage(pos, frames);
		}
		else{
		    miss++;
		    addPage(id, frames, N);
		}
        }
    }
    fprintf(output, "hit=%f miss=%f ratio=%f", hit, miss, hit/miss);
}
