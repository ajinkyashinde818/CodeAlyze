#include <stdio.h>

int main(void){
    int K,N,i;
    int forw[1000000];
    int sa[1000000];
    scanf("%d",&K);
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&forw[i]);
    }
    int max,temp;
    max=K-(forw[N-1]-forw[0]);
    for(i=0;i<N-1;i++){
        temp=forw[i+1]-forw[i];
        if(temp>max){
            max=temp;
        }
    }
    temp=K-max;
    printf("%d",temp);
    
    return 0;

}
