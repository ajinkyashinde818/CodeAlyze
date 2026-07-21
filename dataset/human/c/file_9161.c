#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,K,i,j=0;
    scanf("%d%d",&N,&K);
    int* h;
    h=(int*)malloc(sizeof(int)*N);
    for(i=0;i<N;i++){
        scanf("%d",&h[i]);
        if(h[i]>=K){
            j++;
        }
    }
    printf("%d\n",j);
    free(h);
    return 0;
}
