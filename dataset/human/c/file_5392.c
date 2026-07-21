#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int N;
int M;
int X;

int check(int **arr, int x)
{
    int *sum;
    int c;
    int d;
    int ans = 1;
    sum = (int *)malloc(sizeof(int) * M);
    for (d = 0; d < M; ++d)
    {
        sum[d] = 0;
        for (c = 0; c < N; ++c)
        {
            sum[d] += abs((x / (int)pow(2, c)) % 2 - 1) * arr[c][d];
        }
        if (sum[d] < X)
        {
            ans *= 0;
        }
    }
    free(sum);
    return ans;
}

int sum(int *C, int x)
{
    int ans = 0;
    int c;
    for (c = 0; c < N; ++c)
    {
        ans += abs((x / (int)pow(2, c)) % 2 - 1) * C[c];
    }
    return ans;
}

int main(void) //code is too dirty
{
    int *C;
    int *a;
    int **A;
    int c;
    int d;
    int temp;
    int x;
    int ans;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &X);
    C = (int *)malloc(sizeof(int) * N);
    a = (int *)malloc(sizeof(int) * N * M);
    A = (int **)malloc(sizeof(int *) * N); //sizeof(int*)
    for (c = 0; c < N; ++c)
    {
        A[c] = &a[M * c];
    }
    for (c = 0; c < N; ++c)
    {
        scanf("%d", &C[c]);
        for (d = 0; d < M; ++d)
        {
            scanf("%d", &A[c][d]);
        }
    }
    if (check(A, 0) == 0)
    {
        printf("-1");
        free(C);
        free(a);
        free(A);
        return 0;
    }
    ans = sum(C, 0);
    for (x = 1; x < (int)pow(2, N); ++x)
    {
        if (check(A, x) == 1)
        {
            temp = sum(C, x);
            if (temp < ans)
            {
                ans = temp;
            }
        }
    }
    printf("%d", ans);
    free(C);
    free(a);
    free(A);
    return 0;
}
