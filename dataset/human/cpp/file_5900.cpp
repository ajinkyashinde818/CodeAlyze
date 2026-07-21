#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;

int n, v[N];
long long c, x[N], y[N], l[N], ml[N], r[N], mr[N];

int main()
{
    scanf("%d%lld", &n, &c);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%d", x + i, v + i);
        y[n + 1 - i] = c - x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        l[i] = l[i - 1] + x[i - 1] - x[i] + v[i];
        ml[i] = max(ml[i - 1], l[i]);
        r[i] = r[i - 1] + y[i - 1] - y[i] + v[n + 1 - i];
        mr[i] = max(mr[i - 1], r[i]);
    }
    long long ans = max(ml[n], mr[n]);
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, l[i] - x[i] + mr[n - i]);
        ans = max(ans, r[i] - y[i] + ml[n - i]);
    }
    printf("%lld", ans);
}
