#include <stdio.h>

int main()
{
    int n, i, num[200005], min, max, benefit = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    min = num[0];
    max = -2000000000000005;
    for (i = 1; i < n; i++)
    {
        if (max < num[i] - min)
            max = num[i] - min;
        if (min > num[i])
            min = num[i];
    }

    printf("%d\n", max);

    return 0;
}
