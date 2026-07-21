#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n, 0);
    ll mi = INT_MAX;
    ll sum = 0;
    int minus = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
            minus++;
        sum += abs(a[i]);
        mi = min(mi, abs(a[i]));
    }
    cout << sum - (minus % 2 == 0 ? 0 : 2 * mi) << endl;
}
