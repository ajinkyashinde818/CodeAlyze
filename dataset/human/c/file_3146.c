#include <stdio.h>

int main(void) {
    int K, N, A[200005], m, x, i;
    scanf("%d%d", &K, &N);
    for (i=0; i<N; i++) scanf("%d", &A[i]);
    m=A[N-1]-A[0];
    // printf("%d\n", m);
    for (i=1; i<N; i++) {
        x=A[i-1]-A[i]+K;
        // printf("%d\n", x);
        if (x<m) m=x; 
    }
    printf("%d", m);
    return 0;
}
