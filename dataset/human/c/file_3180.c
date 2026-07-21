#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int K, N;
    int i;
    int ans = 0;
    int A[200000];
    int dis[200000];
    
    scanf("%d %d", &K, &N);
    
    for (i = 0; i < N; i ++) {
        scanf(" %d", &A[i]);
    }
    
    for (i = 0; i < N - 1; i ++) {
        dis[i] = A[i + 1] - A[i];
    }
    
    dis[N - 1] = A[0] + (K - A[N - 1]);
    
    qsort(dis, N, sizeof(int), compare_int);
    
    for (i = 0; i < N - 1; i ++) {
        ans += dis[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}
