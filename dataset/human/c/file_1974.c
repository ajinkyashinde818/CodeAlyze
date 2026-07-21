#include <stdio.h>

int N, A[21], B[51], C[51];
int i, s = 0, p = -1;

int main() {
        scanf("%d", &N);

        for (i = 1; i <= N; i++) {
                scanf("%d", &A[i]);
        }

        for (i = 1; i <= N; i++) {
                scanf("%d", &B[i]);
        }

        for (i = 1; i < N; i++) {
                scanf("%d", &C[i]);
        }

        for (i = 1; i <= N; i++) {
                s += B[A[i]];
                if (A[i] == p + 1) {
                        s += C[p];
                }
                p = A[i];
        }

        printf("%d\n", s);

        return 0;
}
