#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
typedef double ld;
ll xs, xe, ys, ye;
ll n;
ll a[1005], b[1005], c[1005];
ld d[1005][1005];
ld ans = 4e18;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &xs, &ys, &xe, &ye, &n);
    for(ll i = 0; i < n; i++)
    {
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            if((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]) < (c[i] + c[j]) * (c[i] + c[j])) d[i][j] = 0;
            else d[i][j] = sqrt((ld)(a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j])) - c[i] - c[j];
        }
    }
    for(ll k = 0; k < n; k++)
    {
        for(ll i = 0; i < n; i++)
        {
            for(ll j = 0; j < n; j++)
            {
                if(d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < n; j++)
        {
            ld t1 = 0, t2 = 0;
            t1 = max(sqrt((a[i] - xs) * (a[i] - xs) + (b[i] - ys) * (b[i] - ys)) - c[i], 0.0);
            t2 = max(sqrt((a[j] - xe) * (a[j] - xe) + (b[j] - ye) * (b[j] - ye)) - c[j], 0.0);
            ans = min(ans, t1 + t2 + d[i][j]);
        }
    }
    ans = min(ans, (ld)sqrt((xs - xe) * (xs - xe) + (ys - ye) * (ys - ye)));
    printf("%.12f", ans);
    return 0;
}
