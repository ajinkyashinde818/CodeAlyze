#include<stdio.h>

int main(){
    int K,N,i;
    scanf("%d %d",&K,&N);
    int A[N];
    for (i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    int max=0;
    for(i=0;i<N-1;i++){
        if(max<A[i+1]-A[i]){
            max=A[i+1]-A[i];
        }
    }
    if(max<K-A[N-1]+A[0]) max=K-A[N-1]+A[0];
    printf("%d",K-max);
    return 0;
}
