#include<stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    
    int K;
    scanf("%d",&K);
    
    int h[N];
    int counter = 0;
    for(int i=0;i<N;i++){
        scanf("%d",&h[i]);
        if(h[i] >= K){
            counter++;
        }
    }
    
    printf("%d\n",counter);
    
    return 0;
}
