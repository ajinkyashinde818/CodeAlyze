#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

int main(void){
    int i,j;
    int N,K,h[100001];
    int answer = 0;
   
    scanf("%d %d",&N,&K);
    for(i = 0;i < N-1;i++){
        scanf("%d\n",&h[i]);
    }
    scanf("%d",&h[i]);
    
    for(i = 0;i < N;i++){
        if(h[i] >= K){
            answer++;
        }
    }
    
    printf("%d\n",answer);
    
    return 0;
}
