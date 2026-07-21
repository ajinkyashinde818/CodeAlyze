#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N, loc = 1, loop = 0, init = 0;
    long long K;
    int *A, *hist;
    scanf("%d %lld", &N, &K);
    A = (int*)malloc(sizeof(int) * (N + 1));
    hist = (int*)malloc(sizeof(int) * (N + 1));
    for (int c = 0; c < N + 1; ++c)
    {
        hist[c] = -1;
    }
    for (int c = 1; c <= N; ++c)
    {
        scanf("%d", A + c);
    }
    for (int c = 0; c < N; ++c)
    {
        hist[loc] = c;
        if (hist[A[loc]] != -1)
        {
            loop = c - hist[A[loc]] + 1;
            init = c - loop + 1;
            break;
        }
        loc = A[loc];
    }
    if (init <= K)
    {
        K -= init;
        K = K % loop;
        K += init;
    }
    loc = 1;
    for (int c = 0; c < K; ++c)
    {
        loc = A[loc];
    }
    printf("%d", loc);
    return 0;
}
