#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
int main(void){
    int i;
    bool arr[100000]={0};
    time_t t;
    srand((unsigned)time(&t));
    FILE *fr;
    fr = fopen("Random_nos.txt","w");
    for(i=0;i<100000;i++){
        //printf("%d\n",i);
        int r = rand()%100000;
        if(!arr[r]){
            fprintf(fr,"%d%c",r,'\n');
            arr[r]=1;
        }
        else
            i--;
    }
    fclose(fr);
    return 0;
}

