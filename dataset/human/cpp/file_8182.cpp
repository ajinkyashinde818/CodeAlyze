#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
set<long long> b;
long long s, x, y, n, tmp;
int main()
{
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
        scanf("%lld", &tmp), a.push_back(tmp), s += tmp;
    x = a[0], y = s - a[0], b.insert(abs(x - y));
    for (long long i = 1; i < n - 1; i++)
        x += a[i], y -= a[i], b.insert(abs(x - y));
    printf("%lld\n", *b.begin());
    return 0;
}
