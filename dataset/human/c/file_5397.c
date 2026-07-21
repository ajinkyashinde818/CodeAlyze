#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, x, c[15], a[15][15], ans = -1;

    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &c[i]);
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    }

    for (int i = 0; i < pow(2, n); i++)
    {
        int total = 0, check[15] = {0}, k = i, flag = 1;
        for (int j = 0; j < n; j++)
        {
            for (int l = 0; l < m; l++)
                check[l] += a[j][l] * (k % 2);

            total += c[j] * (k % 2);
            k /= 2;
        }

        for (int l = 0; l < m; l++)
        {
            if (check[l] < x)
                flag = 0;
        }

        if (flag && (ans > total || ans == -1))
            ans = total;
    }

    printf("%d", ans);
    return 0;
}
