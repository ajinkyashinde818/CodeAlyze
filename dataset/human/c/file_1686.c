#include <stdio.h>

int main()
{
    int N, a[100], b[100], c[100], i, sum, temp;
    scanf("%d", &N);
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 1; i < N; i++)
    {
        scanf("%d", &c[i]);
    }
    sum = 0;
    temp = 10000;
    for (i = 1; i <= N; i++)
    {
        sum = sum + b[a[i]];
        if (a[i] - 1 == temp)
        {
            sum = sum + c[a[i - 1]];
        }
        temp = a[i];
    }
    printf("%d", sum);
    return 0;
}
