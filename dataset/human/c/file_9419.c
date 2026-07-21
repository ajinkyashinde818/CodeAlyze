#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int d, x;
    scanf("%d %d", &d, &x);
    int i;
    int ans = 0;
    int a;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        ans += ((d - 1) / a);
        ans++;
    }
    ans += x;
    printf("%d\n", ans);
    return 0;
}
