#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    long long int n, m, x, ans = 1000000000000;
    scanf("%lld %lld %lld", &n, &m, &x);

    long long int book[n + 1][m + 1], C[n + 1];
    long long int money, i, j, k, l, skill[m + 1];
    int ok;

    for (l = 0; l < m; l++)
    {

        skill[l] = 0;
    }

    for (i = 0; i < n; i++)
    {

        scanf("%lld", &C[i]);

        for (j = 0; j < m; j++)
        {
            scanf("%lld", &book[i][j]);
        }
    }

    k = pow(2, n);
    for (i = 0; i < k; i++)
    {
        ok = 1;

        for (j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                money += C[j];

                for (l = 0; l < m; l++)
                {

                    skill[l] += book[j][l];
                }
            }
        }
        // printf("%lld\n", skill[0]);

        for (l = 0; l < m; l++)
        {
            if (skill[l] < x)
            {
                ok = 0;
                break;
            }
        }

        if (ok == 1)
        {
            if (ans > money)
            {
                ans = money;
            }
        }

        money = 0;
        for (l = 0; l < m; l++)
        {

            skill[l] = 0;
        }
    }
    if (ans == 1000000000000)
    {
        printf("-1");
    }
    else
    {
        printf("%lld", ans);
    }

    return (0);
}
