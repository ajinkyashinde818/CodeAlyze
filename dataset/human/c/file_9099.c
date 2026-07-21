#include <stdio.h>

int main(void){
    //input 
    int N,K;
    scanf("%d%d",&N,&K);
    int h[N];
    for(int i = 0; i < N; i++)
    scanf("%d",&h[i]);

    //culcu
    int count = 0;
    for(int i = 0; i < N; i++){
        if(h[i]>=K){
            count ++;
        }
    }

    printf("%d\n",count);



    //printf("Nは%dKは%d\n",N,K);
    
}
