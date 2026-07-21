#include <stdio.h>
int main()
{
    int r, g, b, n, ans = 0;
    int sr, sg, sb;
    scanf("%d%d%d%d", &r, &g, &b, &n);
    for (int i = 0; i <= n; i += r)
    {
        for (int j = i; j <= n; j += g)
        {
            if ((n - j) % b == 0)
            {
                ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
