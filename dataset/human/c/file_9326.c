#include<stdio.h>

int main(){
    int N;
    int K;
    int a = 0;

    scanf("%d%d",&N,&K);
    int h[N];
    for(int i = 0; i < N; i++){
        scanf("%d",&h[i]);
        if(h[i] >= K)a += 1;
    }
    printf("%d",a);
    return 0;
}
