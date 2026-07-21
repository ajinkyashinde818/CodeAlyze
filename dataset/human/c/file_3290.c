#include <stdio.h>

#define abs(a) ((a)>0 ? (a) : -(a) )

int main(){
    int K, N, i;
    scanf("%d%d", &K, &N);
    int A[N+1];
    for(i=0; i<N; i++){
        scanf("%d", A+i);
    }
    A[N] = K + A[0];
    int max = 0, buf;
    for(i=0; i<N; i++){
        buf = abs(A[i]-A[i+1]);
        max = max<buf ? buf : max ;
    }
    printf("%d\n", K-max);
    return 0;
}
