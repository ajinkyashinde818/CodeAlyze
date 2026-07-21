#include<stdio.h>
int main(void){
    int N,ans=0,rm=0;
    scanf("%d",&N);
    int A[N],B[N],C[N-1];
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<N-1;i++){
        scanf("%d",&C[i]);
    }
    for(int i=0;i<N;i++){
        if(A[i]==A[i+1]-1){
            rm=A[i]-1;
            ans+=C[rm];
        }
        ans+=B[i];
    }
    printf("%d\n",ans);
    return 0;
}
