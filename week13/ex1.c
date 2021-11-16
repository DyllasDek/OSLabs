#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    int res;
    int proc;
    
    puts("Enter number of resource types:");
    scanf("%d",&res);
    puts("Enter number of processes:");
    scanf("%d",&proc);
    
    int avail[res];
    int total[res];
    int finish[proc];
    int alloc[proc][res];
    int request[proc][res];;

    //FILE *fptr = fopen("input_dl.txt", "r");
    FILE *fptr = fopen("input_ok.txt", "r");

    for(int i = 0;i < res;i++){
        int num = fgetc(fptr);
        if((num != ' ') && (num!= '\n')){
            total[i] = num - '0';
        }
        else{
            i--;
        }
    }

    for(int i = 0;i<res;i++){
        int num = fgetc(fptr);
        if(num != ' ' && num!= '\n'){
            avail[i] = num - '0';
        }
        else{
            i--;
        }
    }

    for(int j = 0;j<proc;j++){
        for(int i = 0;i<res;i++){
            int num = fgetc(fptr);
            if(num != ' ' && num!='\n'){
                alloc[j][i] = num - '0';
            }else{
                i--;
            }
        }
    }

    for(int j = 0;j<proc;j++){
        for(int i = 0;i<res;i++){
            int num = fgetc(fptr);
            if(num != ' ' && num!='\n'){
                request[j][i] = num - '0';
            }else{
                i--;
            }
        }
    }

    for(int i = 0;i<proc;i++){
        finish[i] = 0;
    }

    for(int i = 0;i<proc;i++){
        int count = 0;
        for(int j = 0;j<res;j++){
            if(request[i][j]!=0){
                count ++;
            }
        }
        if(count == 0){
            finish[i] = 1;
        }
    }

    int count = 0;
    int process ;
    for(int i = 0;i<proc;i++){
        int c = 0;
        for(int j = 0;j<res;j++){
            if(request[i][j] > avail[j]){
                c++;
            }
            if(c==0 && finish[i] == 0){
                count ++;
                process =  i;
            }
        }
    }
    
    if(count ==0){
        process = -1;
    }

    while(process != -1){
        finish[process] = 1;
        for(int i = 0;i< res;i++){
            avail[i] = avail[i]+alloc[process][i];
        }
        count = 0;
        for(int i = 0;i<proc;i++){
            int c = 0;
            for(int j = 0;j<res;j++){
                if(request[i][j] > avail[j]){
                    c++;
                }
                if(c==0 && finish[i] == 0){
                    count ++;
                    process =  i;
                }
            }
        }
        if(count ==0){
            process = -1;
        }
    }

    int dcount = 0;
    for(int i = 0;i<proc;i++){
        if(finish[i]==0){
            dcount++;
            printf("Deadlock on %d process\n",i);
        }
    }
    if(dcount==0){
        printf("No deadlocks\n");
    }
    fclose(fptr);
    return 0;
}
