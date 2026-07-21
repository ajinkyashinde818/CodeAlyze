#include<stdio.h>
int main(void){
    int N,K;
    int h[100000];
    int count=0;
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
        }
        for(int i=0;i<N;i++){
            if(K<=h[i]){
                count=count+1;
            }
        }
    printf("%d\n",count);
}
