#include<stdio.h>

int main()
{
    int N,i,sum=0;
    scanf("%d\n", &N);
    int A[N],B[N],C[N];
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    for(i=0;i<N;i++){
        scanf("%d", &B[i]);
    }
    for(i=0;i<N-1;i++){
        scanf("%d", &C[i]);

    }
    for(i=0,sum=0;i<N;i++){
        if((A[i]-A[i-1])==1&&A[i]!=1){
            sum=sum+B[A[i]-1]+C[A[i]-2];
        }
        else{
            sum=sum+B[A[i]-1];
        }
    }
    printf("%d", sum);

    return 0;
}
