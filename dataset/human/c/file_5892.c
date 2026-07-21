#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ll long long

ll min(ll x, ll y)
{
    return x < y ? x : y;
}

ll max(ll x, ll y)
{
    return x > y ? x : y;
}

int main()
{
    int n;
    scanf("%d", &n);
    ll minp, res = -(1 << 31), x;
    scanf("%lld\n", &minp);
    for (int i = 1; i < n; i++)
    {
        scanf("%lld\n", &x);
        res = max(res, x - minp);
        minp = min(x, minp);
    }
    printf("%d\n", res);
}
