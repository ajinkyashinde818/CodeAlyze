#include<stdio.h>

int main(){

    long N=0;
    int K=0;
    int h[100001]={};
    long can=0;
    scanf("%ld %d",&N,&K);
    
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
    }

    for(int i=0;i<N;i++){
        if(h[i]>=K){
            can++;
        }
    }

    printf("%ld\n",can);

    return 0;
}
