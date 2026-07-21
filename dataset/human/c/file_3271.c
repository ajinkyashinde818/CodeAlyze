#include<stdio.h>

int main(void){
    int K,N,i;
    scanf("%d %d",&K,&N);
    int A[N];
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    int max=K-A[N-1]+A[0];
    for(i=1;i<N;i++){
        if(max<A[i]-A[i-1]){
            max=A[i]-A[i-1];
        }
    }
    printf("%d\n",K-max);
    return 0;
}
