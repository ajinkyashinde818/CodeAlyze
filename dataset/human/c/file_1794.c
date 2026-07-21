#include <stdio.h>

int main() {
    int N;
    scanf("%d",&N);
    int A[N];
    int B[N];
    int C[N];
    int ans = 0;
    for (int i = 0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    for (int i = 0; i<N; i++) {
        scanf("%d",&B[i]);
    }
    for (int i = 0; i<N-1; i++) {
        scanf("%d",&C[i]);
    }
    for (int i = 0; i<N; i++) {
        ans = ans + B[(A[i]-1)];
        if (A[i] - 1 == A[i-1]) {
            ans = ans + C[A[i]-2];
        }
    }
    printf("%d",ans);
    return 0;
}
