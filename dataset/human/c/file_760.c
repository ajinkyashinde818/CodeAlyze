#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    char s[100005];
    scanf("%s", s);
    long long int ans = 1, p = 1000000007;
    int count[30];
    int i;
    for (i = 0; i < 30; i++)
        count[i] = 0;
    for (i = 0; i < n; i++)
        count[s[i] - 'a']++;
    for (i = 0; i < 30; i++)
    {
        ans *= count[i] + 1;
        ans %= p;
    }
    ans--;
    if (ans < 0)
        ans += p;
    printf("%lld\n", ans);
    return 0;
}
