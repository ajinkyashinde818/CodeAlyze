#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,K,*h,c=0;
    scanf("%d %d",&N,&K);
    h = malloc(sizeof(int)*N);
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
        if(h[i] >= K) c++;
    }
    printf("%d",c);
    return 0;
}
