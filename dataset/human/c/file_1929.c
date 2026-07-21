#include <stdio.h>

int main(int argc, const char * argv[]) {
    int N;
    int A[20];
    int B[20];
    int C[20];
    int result = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &B[i]);
    }
    for (int i = 1; i <= N - 1; i++) {
        scanf("%d", &C[i]);
    }
    for (int i = 1; i <= N - 1; i++) {
        result += B[A[i]];
        if ((A[i] + 1) == A[i + 1]) {
            result += C[A[i]];
        }
    }
    result += B[(A[N])];
    printf("%d", result);
    return 0;
}
