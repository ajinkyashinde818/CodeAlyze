#include<stdio.h>

int main(void){
    
    int N,K,i,h[100001],ans = 0;

    scanf("%d %d",&N,&K);
    for(i = 0;i < N;i++){
        scanf("%d",&h[i]);
    }

    for(i = 0;i < N;i++){
        if(h[i] >= K){
            ans++;
        }
    }

    printf("%d",ans);
    return 0;
}
