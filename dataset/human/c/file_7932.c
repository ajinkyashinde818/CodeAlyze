#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define DEBUG 0
int* array;
int N;
int L;
int minicount;
void Print_Array(void);
void shift(void);
int Find_min(int start);
int main(){
    scanf("%d %d",&N,&L);
    if(DEBUG)printf("N = %6d\nL = %6d\n",N,L);
    array = malloc(sizeof(int)*N);
    if(array == NULL){
        if(DEBUG)printf("Out of memory\n");
return 1; }
    for(int i = 0; i< N; i++){
        scanf("%d",&array[i]);
    }
    if(DEBUG)Print_Array();
    shift();
}
void shift(void){
    int index = 0;
    int min = Find_min(index);
    printf("%d",min);
while(index+L < N){
if(array[index+L]<min){
    min = array[index+L];
    minicount = 1;
    printf(" %d",min);
}else{
    if(array[index+L] == min){
        if(array[index] != min){
           minicount ++;
}
printf(" %d",min);
}else{
if(array[index]!=min){
    printf(" %d",min);
}else{
    if(minicount>1){
       minicount --;
        printf(" %d",min);
}else{
    min = Find_min(index+1);
    printf(" %d",min);
                    }
} }
}
index++; }
printf("\n");
}

int
Find_min(int start){
int i;
int min = INT_MAX;
minicount = 0;
for(i = 0; i< L; i++){
    if(array[start+i] < min){
        min = array[start+i];
       minicount = 1;
    }else if(array[start+i] == min){
       minicount ++;
} }
return min; }
void Print_Array(void){
    int i;
    printf("array  : ");
    for (i = 0; i< N ; i++){
        printf("%3d",array[i]);
    }
    printf("\n");
}
