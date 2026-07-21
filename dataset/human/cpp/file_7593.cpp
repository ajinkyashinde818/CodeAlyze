#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll g = gcd(a, b);
    return a / g * b;
}

int main()
{
    long long N;
    scanf("%lld", &N);
    std::vector<long long> a(N);
    ll sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        a[i] = x;
    }
    ll snuke = 0;
    ll arai = sum;
    ll sub = LONG_MAX;
    for (size_t i = 0; i < N - 1; i++)
    {
        snuke += a[i];
        arai -= a[i];
        sub = min(sub, abs(snuke - arai));
    }
    cout << sub << endl;
    return 0;
}
