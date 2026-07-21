#include<stdio.h>
int main()
{
    int n, d, x, a, i, ans = 0;
    scanf("%d%d%d", &n, &d, &x);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        ans += d / a + 1;
        if (d%a == 0)
            ans--;
    }
    ans += x;
    printf("%d", ans);
    return 0;
}
