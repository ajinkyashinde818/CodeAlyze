#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, g, b, n;
    scanf("%d %d %d %d", &r, &g, &b, &n);
    int i, j, k, ans = 0;
    for (i = 0; i * r <= n; i++)
    {
        for (j = 0; j * g <= n; j++)
        {
            k = n - (i * r + j * g);
            if (k >= 0 && k % b == 0)
            {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
