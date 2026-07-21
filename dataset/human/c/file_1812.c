#include <stdio.h>
int main(void)
{
    int N, score = 0;
    scanf("%d", &N);
    int A[N], B[N], C[N - 1];
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &A[j]);
    }
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &B[j]);
    }
    for (int j = 0; j < N - 1; j++)
    {
        scanf("%d", &C[j]);
    }
    for (int i = 0; i < N; i++)
    {
        score += B[i];
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i + 1] - A[i] == 1)
        {
            score += C[A[i]-1];
        }
    }
    printf("%d", score);
    return 0;
}
