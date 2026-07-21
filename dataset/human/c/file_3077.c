#include <stdio.h>

int main(void) {
    int k, n, i, max;
    scanf("%d %d", &k, &n);

    int A[n+1];
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    A[n] = k + A[0];
    max = 0;

    for (i = 1; i <= n; i++) {
        if (max < A[i] - A[i-1]) max = A[i]-A[i-1];
    }
    printf("%d\n", k - max);
    return 0;
}
