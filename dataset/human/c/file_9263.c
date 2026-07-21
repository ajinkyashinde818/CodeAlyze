#include<stdio.h>

int main(void){
    int N,K;
    int i;
    scanf("%d%d",&N,&K);

    int h[N];
    int count=0;

    for(i=0;i<N;i++){
        scanf("%d",&h[i]);
        if(K<=h[i]){
            count++;
        }
    }

    printf("%d",count);

    return 0;
}
