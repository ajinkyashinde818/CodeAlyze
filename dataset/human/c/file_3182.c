#include <stdio.h>
int main(void){
    int K,N;
    int A[2*1000000];
    scanf("%d%d",&K,&N);
    
    int i;
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    
    int max = 0;
    
    for(i=0;i<N-1;i++){
        if(max<A[i+1]-A[i]){
            max = A[i+1]-A[i];
        }
    }
    if(max<K-A[N-1]+A[0]){
        max = K-A[N-1]+A[0];
    }
    
    printf("%d\n",K-max);
}
