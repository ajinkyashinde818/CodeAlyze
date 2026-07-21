#include<stdio.h>
int main(){
    int N,K,i;
    int h[100000];
    int safe = 0;
    scanf("%d %d",&N,&K);
    for(i = 0 ; i < N ; i++){
        scanf("%d",&h[i]);
    }
    for(i = 0 ; i < N ; i++){
        if(h[i] >= K){
            safe++;
        }
    }
    printf("%d\n",safe);
    return 0;
}
