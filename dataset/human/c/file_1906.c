#include <stdio.h>

int main(){
    int N,ans=0;
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
        ans+=B[i];
    }
    for(int i=0;i<N-1;i++){
        if(A[i+1]==A[i]+1){
            ans+=C[A[i]-1];
        }
    }
    printf("%d",ans);
    return 0;
}
