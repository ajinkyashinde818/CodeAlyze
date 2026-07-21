#include<stdio.h>

int main(void){
    long K,N,max;
    long index[200020];
    int i,j;

    scanf("%ld %ld",&K,&N);

    for(i=0;i<N;i++){
        scanf("%ld",&index[i]);
    }

    max = 0;
    for(i=0;i<N-1;i++){
        if(index[i+1]-index[i]>max){
            max = index[i+1]-index[i];
        }
    }

    if(K-index[i]+index[0] > max){
        max = K-index[i]+index[0];
    }

    printf("%ld",K-max);
    return 0;

}
