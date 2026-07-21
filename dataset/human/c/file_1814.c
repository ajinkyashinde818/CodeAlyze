#include <stdio.h>
#include <stdlib.h>

int main(){
    // 入力-----------------------
    int N,i,j;
    scanf("%d",&N);
    int *A = malloc(sizeof(int)*N);
    int *B = malloc(sizeof(int)*N);
    int *C = malloc(sizeof(int)*(N-1));
    for(i=0;i<N;i++) {
        scanf("%d",&j);
        A[i]=j-1;
    }
    for(i=0;i<N;i++) scanf("%d",&B[i]);
    for(i=0;i<N-1;i++) scanf("%d",&C[i]);
    // 処理------------------------
    int ans = 0;
    for(i=0;i<N;i++){
        ans += B[A[i]];
        if(i != N-1 && A[i]+1==A[i+1]) ans+=C[A[i]];
    }
    // 出力
    printf("%d\n",ans);
    return 0;
}
