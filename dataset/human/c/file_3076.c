#include <stdio.h>

int main(void)
{
    int K, N;

    scanf("%d", &K);
    scanf("%d", &N);
    int A[N], B[N], n;
    n = N - 1;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    };
    int l, m, d, D = 0;
    for(int j = 0; j < n; j++)
    {
        m = j + 1;

       d =  A[m] - A[j];

       if(D < d)
            D = d;
    };

    if(D < K - A[n] + A[0])
        D = K - A[n] + A[0];
    
    printf("%d\n", K - D);

    return 0;
}
