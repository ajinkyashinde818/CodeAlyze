#include<stdio.h>
#define M 1000001
#define mod 10007
int main(void){
    int K,N,A[400000];
    scanf("%d %d",&K,&N);
    for (int i=0; i<N; i++) {
        scanf("%d",&A[i]);
        A[i+N]=A[i]+K;
    }
    int max=0,sum=0;
    for (int i=0; i<N; i++) {
        if(A[i+1]-A[i]>max){
            max=A[i+1]-A[i];
        }
    }
    
    printf("%d\n",K-max);
    return 0;
}
