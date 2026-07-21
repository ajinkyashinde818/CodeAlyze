#include <stdio.h>

int main(void)
{
    int count=0,N,K,h[100001];
    int i;
    
    scanf("%d %d",&N,&K);
    
    for(i=0; i<N; i++){
        scanf("%d",&h[i]);
    }
    
    for(i=0; i<N; i++){
        if(h[i] >= K){
            count++;
        }
    }
 
    printf("%d\n",count);
        
    return 0;
}
