#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(void)
{
    int K = 0;
    int N = 0;
    int A[1000000];
    scanf("%d %d", &K,&N);
    int n = 0;//一時置き換え
    while (n < N)
    {
        scanf("%d",&A[n]);
        n++;
    }

    qsort(A,N, sizeof(int), compare);
    int dis[1000000];
    int i,MAX=0;
    for (i = 0; i < N; i++)
    {
        if(i!=N-1){
        dis[i] = A[i + 1] - A[i];
        }
        else
            dis[i] = K+A[0] - A[i];
        if(MAX<dis[i]){
            MAX = dis[i];
        }
    }

    printf("%d\n", K - MAX);
    return 0;
}
