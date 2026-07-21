#include<stdio.h>

int main(void){
    int i,N,D,X;
    scanf("%d",&N);
    scanf("%d%d",&D,&X);
    int A[N];
    for(i = 0;i < N;i++) scanf("%d",&A[i]);
    int ans = X;

    for(i=0;i<N;i++) ans += (D-1)/A[i] + 1;

    printf("%d",ans);
    return 0;
}
