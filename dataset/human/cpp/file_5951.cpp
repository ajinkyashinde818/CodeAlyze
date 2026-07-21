#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    ll C;
    cin >> C;
    vector<ll> x(n), v(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> v[i];
    ll s = 0;
    for (int i = 0; i < n; ++i)
        s += v[i];
    vector<ll> prawo2(n);
    vector<ll> lewo2(n);
    ll zysk = 0;
    for (int i = 0; i < n; ++i)
    {
        zysk += v[i];
        prawo2[i] = zysk - 2 * x[i];
        lewo2[i] = (s - zysk + v[i]) - 2 * (C - x[i]);
    }
    vector<ll> prawo1(n);
    vector<ll> lewo1(n);
    zysk = 0;
    for (int i = 0; i < n; ++i)
    {
        zysk += v[i];
        prawo1[i] = zysk - x[i];
        lewo1[i] = (s - zysk + v[i]) - (C - x[i]);
    }
    ll odp = 0;
    multiset<ll> S;
    for (int i = 0; i < n; ++i)
        S.insert(-prawo1[i]);
    for (int i = n - 1; i >= 0; --i)
    {
        S.erase(S.find(-prawo1[i]));
        if (S.size() == 0)
            break;
        ll x = -(*S.begin());
        odp = max(odp, lewo2[i] + x);
    }
    S.clear();
    for (int i = 0; i < n; ++i)
        S.insert(-lewo1[i]);
    for (int i = 0; i < n; ++i)
    {
        S.erase(S.find(-lewo1[i]));
        if (S.size() == 0)
            break;
        ll x = -(*S.begin());
        odp = max(odp, prawo2[i] + x);
    }
    for (int i = 0; i < n; ++i)
    {
        odp = max(odp, prawo1[i]);
        odp = max(odp, lewo1[i]);
    }
    cout << odp;
    return 0;
}
