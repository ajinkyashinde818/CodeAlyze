#include<stdio.h>
int main(void){
    int N,K,i,x=0;
    scanf("%d%d",&N,&K);
    int h[N];
    for(i=0;i<=N-1;i++){
        scanf("%d",&h[i]);
        if(h[i]>=K)x++;
    }
    printf("%d",x);
    return 0;
}
