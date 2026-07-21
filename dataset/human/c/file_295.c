#include <stdio.h>

int main()
{
        int n, num = 0;
        long long a[100010], sma = 1000000000000, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
                scanf("%lld", &a[i]);
                if (a[i] < 0)
                {
                        num++;
                        a[i] *= -1;
                }
                if (sma > a[i])
                {
                        sma = a[i];
                }
                sum += a[i];
        }
        if (num % 2 == 1)
        {
                sum -= 2 * sma;
        }
        printf("%lld\n", sum);
}
