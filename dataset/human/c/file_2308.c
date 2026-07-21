#include <stdio.h>

int main(void) {
    int N, K, S, A[100005], i;
    scanf("%d%d%d", &N, &K, &S);
    for (i=1; i<=K; i++) A[i]=S;
    for (i=K+1; i<=N; i++) {
        if (S!=1000000000) A[i]=S+1;
        else A[i]=1;
    }
    for (i=1; i<=N; i++) {
        printf("%d", A[i]);
        if (i!=N) printf(" ");
    }
    return 0;
}
