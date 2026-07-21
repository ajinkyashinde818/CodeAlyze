#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int N;
    long long K;
    int A[200000];
    long long F[200000];
    int now, next;

    scanf("%d %lld", &N, &K);
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
        F[i] = -1;
    }

    now = 0;
    F[0] = 0;
    for(long long i = 0; i < K; i++) {
        next = A[now];
        if(F[next] != -1) {
            i += ((K - i - 1) / (i + 1 - F[next]) ) * (i + 1 - F[next]);
        }
        else {
            F[next] = i + 1;
        }
        now = next;
    }

    printf("%d\n", ++now);

    return 0;
}
