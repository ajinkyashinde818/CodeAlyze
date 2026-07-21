#include <stdio.h>

int main(void){
    int N, A[21], B[21], C[21], i, s;
    scanf("%d", &N);
    s=0;
    for (i=1; i<=N; i++) scanf("%d", &A[i]);
    for (i=1; i<=N; i++) {
        scanf("%d", &B[i]);
        s+=B[i];
    }
    for (i=1; i<=N-1; i++) scanf("%d", &C[i]);
    for (i=1; i<=N-1; i++) {
        if (A[i]+1==A[i+1]) s+=C[A[i]];
    }
    printf("%d", s);
    return 0;
}
