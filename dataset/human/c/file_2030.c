#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int ans = 0;
    while (c > 0)
    {
        c--;
        ans++;
        if (b > 0)
        {
            b--;
            ans++;
            continue;
        }
        if (a > 0)
        {
            a--;
            continue;
        }
        c = 0;
    }
    if (b > 0)
        ans += b;
    printf("%d\n", ans);
    return 0;
}
