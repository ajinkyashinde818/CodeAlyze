#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

ll v[N];

int main()
{
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%lld", &v[i]);
        sum += v[i];
    }
    ll ans = abs(v[0] - (sum - v[0]));
    ll k = v[0];
    for(int i = 1; i < n - 1; ++i)
    {
        k += v[i];
        ans = min(ans, abs(k - (sum - k)));
    }
    printf("%lld\n", ans);
    return 0;
}
