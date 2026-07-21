#include <stdio.h>

int main()
{
    int N, K, h[100001], i, count = 0;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &h[i]);
    }
    for (i = 1; i <= N; i++)
    {
        if (h[i] >= K)
        {
            count = count + 1;
        }
    }
    printf("%d", count);
    return 0;
}
