#include <stdio.h>

int main(void)
{
    int K;
    int N;
    int A[200000];
    int max;

    scanf("%d %d", &K, &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    max = K - A[N - 1] + A[0];
    for (int j = 2; j < N; j++)
        if (max < A[j] - A[j - 1])
            max = A[j] - A[j - 1];
    printf("%d\n", K - max);
}
